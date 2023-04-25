#include <stdio.h>
#include <stdlib.h>

int gpu_stream_test() {
    char *command;
    int ret = asprintf(&command, "../spatter -pFILE=../../standard-suite/basic-tests/gpu-stream.json");
    if (ret == -1 || system(command) != EXIT_SUCCESS) {
        printf("Test failure on %s", command);
        return EXIT_FAILURE;
    }
    free(command);
    return EXIT_SUCCESS;
}

int gpu_ustride_test() {
    char *command;
    int ret = asprintf(&command, "../spatter -pFILE=../../standard-suite/basic-tests/gpu-ustride.json");
    if (ret == -1 || system(command) != EXIT_SUCCESS) {
        printf("Test failure on %s", command);
        return EXIT_FAILURE;
    }
    free(command);
    return EXIT_SUCCESS;
}

int gpu_amg_test() {
    char *command;
    int ret = asprintf(&command, "../spatter -pFILE=../../standard-suite/app-traces/amg_gpu.json");
    if (ret == -1 || system(command) != EXIT_SUCCESS) {
        printf("Test failure on %s", command);
        return EXIT_FAILURE;
    }
    free(command);
    return EXIT_SUCCESS;
}
int gpu_lulesh_test() {
    char *command;
    int ret = asprintf(&command, "../spatter -pFILE=../../standard-suite/app-traces/lulesh_gpu.json");
    if (ret == -1 || system(command) != EXIT_SUCCESS) {
        printf("Test failure on %s", command);
        return EXIT_FAILURE;
    }
    free(command);
    return EXIT_SUCCESS;
}
int gpu_nekbone_test() {
    char *command;
    int ret = asprintf(&command, "../spatter -pFILE=../../standard-suite/app-traces/nekbone_gpu.json");
    if (ret == -1 || system(command) != EXIT_SUCCESS) {
        printf("Test failure on %s", command);
        return EXIT_FAILURE;
    }
    free(command);
    return EXIT_SUCCESS;
}
int gpu_pennant_test() {
    char *command;
    int ret = asprintf(&command, "../spatter -pFILE=../../standard-suite/app-traces/pennant_gpu.json");
    if (ret == -1 || system(command) != EXIT_SUCCESS) {
        printf("Test failure on %s", command);
        return EXIT_FAILURE;
    }
    free(command);
    return EXIT_SUCCESS;
}

int main(int argc, char **argv) {
    if (gpu_stream_test() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }
    if (gpu_ustride_test() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }
    if (gpu_amg_test() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }
    if (gpu_lulesh_test() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }
    if (gpu_nekbone_test() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }
    if (gpu_pennant_test() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

