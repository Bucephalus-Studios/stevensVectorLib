#include <benchmark/benchmark.h>
#include "stevensVectorLib.hpp"
#include <vector>
#include <algorithm>

static void Contains_Small(benchmark::State& state)
{
    std::vector<int> vec(100);
    for (int i = 0; i < 100; ++i) vec[i] = i;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::contains(vec, 50));
    }
}
BENCHMARK(Contains_Small);

static void Contains_Small_Baseline(benchmark::State& state)
{
    std::vector<int> vec(100);
    for (int i = 0; i < 100; ++i) vec[i] = i;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(std::find(vec.begin(), vec.end(), 50) != vec.end());
    }
}
BENCHMARK(Contains_Small_Baseline);

static void Contains_Medium(benchmark::State& state)
{
    std::vector<int> vec(10000);
    for (int i = 0; i < 10000; ++i) vec[i] = i;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::contains(vec, 5000));
    }
}
BENCHMARK(Contains_Medium);

static void Contains_Medium_Baseline(benchmark::State& state)
{
    std::vector<int> vec(10000);
    for (int i = 0; i < 10000; ++i) vec[i] = i;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(std::find(vec.begin(), vec.end(), 5000) != vec.end());
    }
}
BENCHMARK(Contains_Medium_Baseline);

static void Contains_Large(benchmark::State& state)
{
    std::vector<int> vec(1000000);
    for (int i = 0; i < 1000000; ++i) vec[i] = i;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::contains(vec, 500000));
    }
}
BENCHMARK(Contains_Large);

static void Contains_Large_Baseline(benchmark::State& state)
{
    std::vector<int> vec(1000000);
    for (int i = 0; i < 1000000; ++i) vec[i] = i;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(std::find(vec.begin(), vec.end(), 500000) != vec.end());
    }
}
BENCHMARK(Contains_Large_Baseline);

static void Contains_NotFound(benchmark::State& state)
{
    std::vector<int> vec(10000);
    for (int i = 0; i < 10000; ++i) vec[i] = i;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::contains(vec, -1));
    }
}
BENCHMARK(Contains_NotFound);

static void Contains_NotFound_Baseline(benchmark::State& state)
{
    std::vector<int> vec(10000);
    for (int i = 0; i < 10000; ++i) vec[i] = i;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(std::find(vec.begin(), vec.end(), -1) != vec.end());
    }
}
BENCHMARK(Contains_NotFound_Baseline);
