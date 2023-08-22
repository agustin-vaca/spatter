#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parse-args.h"

#define STRLEN (1024)

//Silence ASAN "invalid aligment requested" error
#ifndef __has_feature
    // GCC does not have __has_feature...
    #define __has_feature(feature) 0
#endif

#if __has_feature(address_sanitizer) || defined(__SANITIZE_ADDRESS__)
const char *__asan_default_options() {
  return "allocator_may_return_null=true";
}
#endif

int custom_test(int indexLength, int* values, int argc, char** argv)
{
    int nrc = 0;
    struct run_config *rc = NULL;

    parse_args(argc, argv, &nrc, &rc);

    if (nrc != 1)
    {
        printf("Test failure on Custom Pattern: Expected number of runs to be 1, actually was %d.\n", nrc);
        return EXIT_FAILURE;
    }

    if (rc == NULL)
    {
        printf("Test failure on Custom Pattern: failed to create or allocate run_config struct.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < indexLength; i++)
    {
        if ((unsigned long)values[i] != rc[0].pattern[i])
        {
            printf("Test failure on Custom Pattern: input pattern does not match parsed pattern!\n");
            return EXIT_FAILURE;
        }
    }

    free(rc);
    return EXIT_SUCCESS;
}


int main ()
{
    int argc_ = 2;
    char **argv_ = (char**)malloc(sizeof(char*) * argc_);

    asprintf(&argv_[0], "./spatter");
    asprintf(&argv_[1], "-p1,2,3,4,5,6,7,8,9");

    int testValues[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    if (custom_test(8, testValues, argc_, argv_) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    sprintf(argv_[1], "-p0");
    int testValues1[1] = {0};
    if (custom_test(1, testValues1, argc_, argv_) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    free(argv_[0]);
    free(argv_[1]);

    return EXIT_SUCCESS;
}
