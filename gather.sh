CL_HELPER_NO_COMPILER_OUTPUT_NAG=1 ./sgbench --backend=opencl --source-len=10 --target-len=10 --index-len=10 --kernel-file=kernels/gather.cl --kernel-name=gather --cl-platform=nvidia --cl-device=titan --validate --block-len=20
