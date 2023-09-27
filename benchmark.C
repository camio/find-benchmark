#include <benchmark/benchmark.h>

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <system_error>

extern int f(float f);
extern int g(float f);

void BM_f(benchmark::State& state) {
    const unsigned int N = state.range(0);
    std::unique_ptr<float[]> a(new float[N]);
    for (size_t i = 0; i<N; ++i)
      a.get()[i] = std::fmod(i, 5.0);
    const float *b = a.get();
    for (auto _ : state) {
      for (size_t i = 0; i < N; ++i)
        benchmark::DoNotOptimize(f(b[i]));
    }
    state.SetItemsProcessed(N * state.iterations());
}

void BM_g(benchmark::State &state) {
  const unsigned int N = state.range(0);
  std::unique_ptr<float[]> a(new float[N]);
  for (size_t i = 0; i < N; ++i)
    a.get()[i] = std::fmod(i, 5.0);
  const float *b = a.get();
  for (auto _ : state) {
    for (size_t i = 0; i < N; ++i)
      benchmark::DoNotOptimize(g(b[i]));
  }
  state.SetItemsProcessed(N * state.iterations());
}

#define ARGS ->Arg(long(1e6))

#define MIX_ARGS                                                               \
  ->Args({long(1e6), long(1e4)})                                               \
      ->Args({long(1e6), long(1e3)})                                           \
      ->Args({long(1e6), long(1e2)})                                           \
      ->Args({long(1e6), long(1e1)})

BENCHMARK(BM_f) ARGS;
BENCHMARK(BM_g) ARGS;

BENCHMARK_MAIN();
