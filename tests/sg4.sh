CL_HELPER_NO_COMPILER_OUTPUT_NAG=1 ./sgbench --backend=opencl --source-len=256 --target-len=256 --index-len=256 --kernel-file=kernels/sg4.cl --kernel-name=sg --cl-platform=nvidia --cl-device=titan --validate --vector-len=4