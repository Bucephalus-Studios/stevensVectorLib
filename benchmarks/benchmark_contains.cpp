#include <benchmark/benchmark.h>
#include "stevensVectorLib.hpp"
#include <vector>

static void BM_Contains_Small(benchmark::State& state)
{
    std::vector<int> vec(100);
    for (int i = 0; i < 100; ++i) vec[i] = i;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::contains(vec, 50));
    }
}
BENCHMARK(BM_Contains_Small);

static void BM_Contains_Medium(benchmark::State& state)
{
    std::vector<int> vec(10000);
    for (int i = 0; i < 10000; ++i) vec[i] = i;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::contains(vec, 5000));
    }
}
BENCHMARK(BM_Contains_Medium);

static void BM_Contains_Large(benchmark::State& state)
{
    std::vector<int> vec(1000000);
    for (int i = 0; i < 1000000; ++i) vec[i] = i;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::contains(vec, 500000));
    }
}
BENCHMARK(BM_Contains_Large);

static void BM_Contains_NotFound(benchmark::State& state)
{
    std::vector<int> vec(10000);
    for (int i = 0; i < 10000; ++i) vec[i] = i;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::contains(vec, -1));
    }
}
BENCHMARK(BM_Contains_NotFound);
