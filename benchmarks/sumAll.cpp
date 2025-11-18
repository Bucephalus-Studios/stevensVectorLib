#include <benchmark/benchmark.h>
#include "stevensVectorLib.hpp"
#include <vector>
#include <numeric>

static void SumAll_Small(benchmark::State& state)
{
    std::vector<int> vec(100);
    for (int i = 0; i < 100; ++i) vec[i] = i;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::sumAll(vec, 0));
    }
}
BENCHMARK(SumAll_Small);

static void SumAll_Small_Baseline(benchmark::State& state)
{
    std::vector<int> vec(100);
    for (int i = 0; i < 100; ++i) vec[i] = i;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(std::accumulate(vec.begin(), vec.end(), 0));
    }
}
BENCHMARK(SumAll_Small_Baseline);

static void SumAll_Medium(benchmark::State& state)
{
    std::vector<int> vec(10000);
    for (int i = 0; i < 10000; ++i) vec[i] = i;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::sumAll(vec, 0));
    }
}
BENCHMARK(SumAll_Medium);

static void SumAll_Medium_Baseline(benchmark::State& state)
{
    std::vector<int> vec(10000);
    for (int i = 0; i < 10000; ++i) vec[i] = i;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(std::accumulate(vec.begin(), vec.end(), 0));
    }
}
BENCHMARK(SumAll_Medium_Baseline);

static void SumAll_Large(benchmark::State& state)
{
    std::vector<int> vec(1000000);
    for (int i = 0; i < 1000000; ++i) vec[i] = i % 1000;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::sumAll(vec, 0));
    }
}
BENCHMARK(SumAll_Large);

static void SumAll_Large_Baseline(benchmark::State& state)
{
    std::vector<int> vec(1000000);
    for (int i = 0; i < 1000000; ++i) vec[i] = i % 1000;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(std::accumulate(vec.begin(), vec.end(), 0));
    }
}
BENCHMARK(SumAll_Large_Baseline);

static void MultiplyAll_Small(benchmark::State& state)
{
    std::vector<int> vec(10);
    for (int i = 0; i < 10; ++i) vec[i] = i + 1;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::multiplyAll(vec, 1));
    }
}
BENCHMARK(MultiplyAll_Small);

static void MultiplyAll_Small_Baseline(benchmark::State& state)
{
    std::vector<int> vec(10);
    for (int i = 0; i < 10; ++i) vec[i] = i + 1;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>()));
    }
}
BENCHMARK(MultiplyAll_Small_Baseline);
