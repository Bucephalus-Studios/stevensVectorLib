#include <benchmark/benchmark.h>
#include "stevensVectorLib.hpp"
#include <vector>

static void BM_SumAll_Small(benchmark::State& state)
{
    std::vector<int> vec(100);
    for (int i = 0; i < 100; ++i) vec[i] = i;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::sumAll(vec, 0));
    }
}
BENCHMARK(BM_SumAll_Small);

static void BM_SumAll_Medium(benchmark::State& state)
{
    std::vector<int> vec(10000);
    for (int i = 0; i < 10000; ++i) vec[i] = i;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::sumAll(vec, 0));
    }
}
BENCHMARK(BM_SumAll_Medium);

static void BM_SumAll_Large(benchmark::State& state)
{
    std::vector<int> vec(1000000);
    for (int i = 0; i < 1000000; ++i) vec[i] = i % 1000;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::sumAll(vec, 0));
    }
}
BENCHMARK(BM_SumAll_Large);

static void BM_MultiplyAll_Small(benchmark::State& state)
{
    std::vector<int> vec(10);
    for (int i = 0; i < 10; ++i) vec[i] = i + 1;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::multiplyAll(vec, 1));
    }
}
BENCHMARK(BM_MultiplyAll_Small);
