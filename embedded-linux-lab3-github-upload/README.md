# Embedded Linux Lab 3

**Debugging, Memory Analysis, Performance Profiling, and PREEMPT_RT on QEMU ARM**

## Overview

This repository collects the source code, logs, configuration files, and report from Embedded Linux Lab 3. Testing was performed on Ubuntu (host) and a QEMU Versatile Express ARM Cortex-A9 (`vexpress-a9`) guest.

### What was implemented

- **GDB debugging:** identified and fixed an out-of-bounds array access (`i <= len`), a use-after-free bug, and 32-bit integer overflow; the fixed ARM application produced an array sum of 150, the message `Hello Embedded Linux`, and a multiplication result of 10000000000.
- **Valgrind:** detected a **100-byte definitely lost** block before the fix; after the fix: **0 bytes in use at exit, 0 errors**.
- **strace and perf:** collected syscall trace/summary and basic performance counters for the host-side test application.
- **PREEMPT_RT:** applied Linux 5.15-rt17 PREEMPT_RT patch; built both a PREEMPT_RT kernel and a normal `PREEMPT_NONE` kernel for ARM. Both comparison kernels have high-resolution timers enabled.
- **cyclictest:** compared latency across three recorded runs of each kernel in QEMU.

## Cyclictest measurements

Command in the QEMU ARM guest:

```sh
/usr/bin/cyclictest -p 80 -t 1 -i 1000 -l 10000 -q
```

Latency units below are **microseconds (µs)**; each run collected 10,000 samples.

| Kernel | Run | Min | Avg | Max |
|---|---:|---:|---:|---:|
| Normal (`PREEMPT_NONE`) | 1 | 70 | 305 | 116859 |
| Normal (`PREEMPT_NONE`) | 2 | 91 | 295 | 2091 |
| Normal (`PREEMPT_NONE`) | 3 | 71 | 260 | 2442 |
| PREEMPT_RT | 1 | 61 | 251 | 3579 |
| PREEMPT_RT | 2 | 78 | 300 | 2851 |
| PREEMPT_RT | 3 | 129 | 259 | 2715 |

- **Mean of per-run average latencies:** Normal **286.67 µs**; PREEMPT_RT **270.00 µs** (about 5.8% lower in this small experiment).
- A large outlier in Normal run 1 (**116859 µs**) and virtualization effects limit any general conclusion; two other Normal runs had lower maximum latency than the RT runs. These results do **not** establish that one kernel always performs better.

## Repository layout

```text
apps/       C source files before/after debugging and memory fixes
configs/    Normal and RT kernel .config snapshots
logs/       GDB notes, Valgrind, strace, perf, kernel build and cyclictest logs
bao_cao/    Final report in Word format
output/     Notes about kernel images and DTB not present in the evidence archive
```

## Important notes

- `logs/gdb_debug_notes.txt` was compiled from GDB screenshots, **not** a verbatim GDB session transcript.
- Host-side `strace`, `perf`, and Valgrind runs are separate from the QEMU ARM cyclictest benchmarks.
- Kernel images (`zImage_normal`, `zImage_rt`) and DTB were **not** present in the evidence ZIP that was supplied for this GitHub package, so they are not included here.
- No credentials or full Linux kernel source tree are required to view this repository. See the report for discussion of the methodology and limitations.

## Report

[Embedded Linux Lab 3 Report (.docx)](bao_cao/Embedded_Linux_Lab3_Report.docx)
