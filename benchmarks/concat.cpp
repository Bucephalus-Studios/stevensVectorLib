#include <benchmark/benchmark.h>
#include "stevensVectorLib.hpp"
#include <vector>

static void Concat_Small(benchmark::State& state)
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
BENCHMARK(Concat_Small);

static void Concat_Small_Baseline(benchmark::State& state)
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
        std::vector<int> result = vec1;
        result.insert(result.end(), vec2.begin(), vec2.end());
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(Concat_Small_Baseline);

static void Concat_Medium(benchmark::State& state)
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
BENCHMARK(Concat_Medium);

static void Concat_Medium_Baseline(benchmark::State& state)
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
        std::vector<int> result = vec1;
        result.insert(result.end(), vec2.begin(), vec2.end());
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(Concat_Medium_Baseline);

static void Concat_Large(benchmark::State& state)
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
BENCHMARK(Concat_Large);

static void Concat_Large_Baseline(benchmark::State& state)
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
        std::vector<int> result = vec1;
        result.insert(result.end(), vec2.begin(), vec2.end());
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(Concat_Large_Baseline);
