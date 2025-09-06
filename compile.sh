#!/bin/bash
set -e

function compile_benchmarks {
  dir_name="$1"
  compile_cmd="$2"
  mkdir -p "$dir_name"
  pushd "$dir_name"
  echo "=================  $dir_name ======================"

  benchmarks="compute_pi compute_primes dhrystone whetstone stream"
  for x in $benchmarks; do
    echo Compiling $x
    eval echo $compile_cmd
    eval $compile_cmd
  done
  echo
  popd
}

compile_benchmarks arm64 'aarch64-linux-gnu-gcc -o $x ../$x.c -static -lm'
compile_benchmarks mips 'mips-linux-gnu-gcc -o $x ../$x.c -static -lm'
compile_benchmarks riscv 'riscv64-linux-gnu-gcc -o $x ../$x.c -static -lm'
compile_benchmarks x86 'x86_64-linux-gnu-gcc -L /usr/x86_64-linux-gnu/lib/ -o $x ../$x.c -static -l:libm-2.35.a'
