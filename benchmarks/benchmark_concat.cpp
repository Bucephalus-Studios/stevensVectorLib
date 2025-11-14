#include <benchmark/benchmark.h>
#include "stevensVectorLib.hpp"
#include <vector>

static void BM_Concat_Small(benchmark::State& state)
{
    std::vector<int> vec1(100);
    std::vector<int> vec2(100);
    for (int i = 0; i < 100; ++i)
    {
        vec1[i] = i;
        vec2[i] = i + 100;
    }

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::concat(vec1, vec2));
    }
}
BENCHMARK(BM_Concat_Small);

static void BM_Concat_Medium(benchmark::State& state)
{
    std::vector<int> vec1(10000);
    std::vector<int> vec2(10000);
    for (int i = 0; i < 10000; ++i)
    {
        vec1[i] = i;
        vec2[i] = i + 10000;
    }

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::concat(vec1, vec2));
    }
}
BENCHMARK(BM_Concat_Medium);

static void BM_Concat_Large(benchmark::State& state)
{
    std::vector<int> vec1(100000);
    std::vector<int> vec2(100000);
    for (int i = 0; i < 100000; ++i)
    {
        vec1[i] = i;
        vec2[i] = i + 100000;
    }

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::concat(vec1, vec2));
    }
}
BENCHMARK(BM_Concat_Large);
