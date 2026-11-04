# Kernel build artifacts

`zImage_normal`, `zImage_rt`, and `vexpress-v2p-ca9.dtb` were built and tested on the Ubuntu development environment, but the original executable files were not included in the uploaded evidence ZIP. This repository therefore does not contain those binaries.

For a reproducible build, use Linux 5.15 source, apply the PREEMPT_RT 5.15-rt17 patch to the RT tree, use the supplied configurations in `configs/`, and cross-compile for ARM with `arm-linux-gnueabi-`.

See `logs/normal_kernel_build.log` and `logs/rt_kernel_rebuild.log` for original build evidence. The RT image is specifically for QEMU Versatile Express `vexpress-a9`.
