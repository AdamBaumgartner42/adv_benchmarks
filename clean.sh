#!/bin/bash
set -e  # exit on error

# List of folders to delete
targets=("arm64" "mips" "riscv" "x86")

for dir in "${targets[@]}"; do
  if [ -d "$dir" ]; then
    echo "Deleting $dir"
    rm -rf "$dir"
  else
    echo "Skipping $dir (not found)"
  fi
done