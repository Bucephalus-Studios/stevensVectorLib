#include <benchmark/benchmark.h>
#include "stevensVectorLib.hpp"
#include <vector>

static void BM_EraseDuplicates_NoDuplicates(benchmark::State& state)
{
    std::vector<int> vec(10000);
    for (int i = 0; i < 10000; ++i) vec[i] = i;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::eraseDuplicateElements(vec));
    }
}
BENCHMARK(BM_EraseDuplicates_NoDuplicates);

static void BM_EraseDuplicates_SomeDuplicates(benchmark::State& state)
{
    std::vector<int> vec(10000);
    for (int i = 0; i < 10000; ++i) vec[i] = i % 100;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::eraseDuplicateElements(vec));
    }
}
BENCHMARK(BM_EraseDuplicates_SomeDuplicates);

static void BM_EraseDuplicates_ManyDuplicates(benchmark::State& state)
{
    std::vector<int> vec(10000);
    for (int i = 0; i < 10000; ++i) vec[i] = i % 10;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::eraseDuplicateElements(vec));
    }
}
BENCHMARK(BM_EraseDuplicates_ManyDuplicates);
