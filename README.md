# find-benchmark

This repository contains the source code for a micro benchmark that compares the
cost of `std::lower_bound` of a small sorted array to the cost of
`std::min_element` with an unsorted array.

## Building

Use the enclosed `Makefile`. A system installation of [Google
benchmark](https://github.com/google/benchmark) is assumed to be available.

## Running

Run the `benchmark` executable. The output should look something like this:

```shell
2022-12-13T21:46:14-05:00
Running ./benchmark
Run on (24 X 2660.09 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x12)
  L1 Instruction 32 KiB (x12)
  L2 Unified 256 KiB (x12)
  L3 Unified 12288 KiB (x2)
Load Average: 1.16, 1.17, 1.12
------------------------------------------------------------------------------------
Benchmark                          Time             CPU   Iterations UserCounters...
------------------------------------------------------------------------------------
BM_f/1000000    2741527 ns      2741047 ns          256 items_per_second=364.824M/s
BM_g/1000000    1558237 ns      1558176 ns          450 items_per_second=641.776M/s
```

## The benchmarks

Each of the benchmarks run one of the two implementations of a very simple
function that finds the closest float in a list of floats.

The benchmarks are in [benchmark.C](benchmark.C) and the two functions are in [f.C](f.C).

## MacOS Notes

Install dependencies

```bsh
brew install google-benchmark
brew install pkg-config
```
