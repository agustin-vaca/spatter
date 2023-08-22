#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <stdlib.h>

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

int uniform_concurrent_test() {
    for (int i = 1; i <= 10; i++) {
        char *command;
        int ret = asprintf(&command, "../spatter -kGS -hUNIFORM:%d:%d -gUNIFORM:%d:%d ", i, i, i, i);
        if (ret == -1 || system(command) != EXIT_SUCCESS) {
            printf("Test failure on %s", command);
            return EXIT_FAILURE;
        }
        free(command);
    }
    return EXIT_SUCCESS;
}

int main(int argc, char **argv) {
    if (uniform_concurrent_test() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
