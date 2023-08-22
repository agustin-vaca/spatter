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

int cpu_stream_test() {
    char *command;
    int ret = asprintf(&command, "../spatter -pFILE=../../standard-suite/basic-tests/cpu-stream.json");
    if (ret == -1 || system(command) != EXIT_SUCCESS) {
        printf("Test failure on %s", command);
        return EXIT_FAILURE;
    }
    free(command);
    return EXIT_SUCCESS;
}

int cpu_ustride_test() {
    char *command;
    int ret = asprintf(&command, "../spatter -pFILE=../../standard-suite/basic-tests/cpu-ustride.json");
    if (ret == -1 || system(command) != EXIT_SUCCESS) {
        printf("Test failure on %s", command);
        return EXIT_FAILURE;
    }
    free(command);
    return EXIT_SUCCESS;
}

int cpu_amg_test() {
    char *command;
    int ret = asprintf(&command, "../spatter -pFILE=../../standard-suite/app-traces/amg.json");
        if (ret == -1 || system(command) != EXIT_SUCCESS) {
            printf("Test failure on %s", command);
            return EXIT_FAILURE;
        }
        free(command);
        return EXIT_SUCCESS;
}

int cpu_lulesh_test() {
    char *command;
    int ret = asprintf(&command, "../spatter -pFILE=../../standard-suite/app-traces/lulesh.json");
        if (ret == -1 || system(command) != EXIT_SUCCESS) {
            printf("Test failure on %s", command);
            return EXIT_FAILURE;
        }
        free(command);
        return EXIT_SUCCESS;
}

int cpu_nekbone_test() {
    char *command;
    int ret = asprintf(&command, "../spatter -pFILE=../../standard-suite/app-traces/nekbone.json");
        if (ret == -1 || system(command) != EXIT_SUCCESS) {
            printf("Test failure on %s", command);
            return EXIT_FAILURE;
        }
        free(command);
        return EXIT_SUCCESS;
}

int cpu_pennant_test() {
    char *command;
    int ret = asprintf(&command, "../spatter -pFILE=../../standard-suite/app-traces/pennant.json");
        if (ret == -1 || system(command) != EXIT_SUCCESS) {
            printf("Test failure on %s", command);
            return EXIT_FAILURE;
        }
        free(command);
        return EXIT_SUCCESS;
}

int main(int argc, char **argv) {
    if (cpu_stream_test() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }
    if (cpu_ustride_test() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }
    if (cpu_amg_test() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }
    if (cpu_lulesh_test() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }
    if (cpu_nekbone_test() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }
    if (cpu_pennant_test() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
