#!/bin/bash
set -e

function run_benchmarks {
  dir_name="$1"
  emu="$2"
  pushd "$dir_name"
  echo "=================  $dir_name ======================"

  cmds="echo
  time echo 100000000 | $emu ./compute_pi
  time echo 100000000 | $emu ./compute_primes | tail -c 100
  $emu ./dhrystone
  $emu ./whetstone 100000
  $emu ./stream"
  while read cmd; do
    echo Running "$cmd"
    eval $cmd
    echo
  done < <(echo "$cmds")
  popd
}

# Native
echo "=================  NATIVE  ======================"
native_arch=$(uname -m)
if [ "$native_arch" = "x86_64" ]; then
  run_benchmarks x86 command
elif [ "$native_arch" = "aarch64" ]; then
  run_benchmarks arm64 command
else
  echo "No native benchmarks for arch: $arch"
fi

# Emu
echo "=================  EMULATION  ======================"
run_benchmarks arm64 qemu-aarch64
run_benchmarks mips qemu-mips
run_benchmarks riscv qemu-riscv64
run_benchmarks x86 qemu-x86_64