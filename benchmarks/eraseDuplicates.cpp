#include <benchmark/benchmark.h>
#include "stevensVectorLib.hpp"
#include <vector>
#include <algorithm>
#include <unordered_set>

static void EraseDuplicates_NoDuplicates(benchmark::State& state)
{
    std::vector<int> vec(10000);
    for (int i = 0; i < 10000; ++i) vec[i] = i;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::eraseDuplicateElements(vec));
    }
}
BENCHMARK(EraseDuplicates_NoDuplicates);

static void EraseDuplicates_NoDuplicates_Baseline(benchmark::State& state)
{
    std::vector<int> vec(10000);
    for (int i = 0; i < 10000; ++i) vec[i] = i;

    for (auto _ : state)
    {
        state.PauseTiming();
        std::vector<int> v = vec;
        state.ResumeTiming();

        std::unordered_set<int> seen;
        auto end = std::remove_if(v.begin(), v.end(), [&seen](int x) {
            return !seen.insert(x).second;
        });
        v.erase(end, v.end());
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(EraseDuplicates_NoDuplicates_Baseline);

static void EraseDuplicates_SomeDuplicates(benchmark::State& state)
{
    std::vector<int> vec(10000);
    for (int i = 0; i < 10000; ++i) vec[i] = i % 100;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::eraseDuplicateElements(vec));
    }
}
BENCHMARK(EraseDuplicates_SomeDuplicates);

static void EraseDuplicates_SomeDuplicates_Baseline(benchmark::State& state)
{
    std::vector<int> vec(10000);
    for (int i = 0; i < 10000; ++i) vec[i] = i % 100;

    for (auto _ : state)
    {
        state.PauseTiming();
        std::vector<int> v = vec;
        state.ResumeTiming();

        std::unordered_set<int> seen;
        auto end = std::remove_if(v.begin(), v.end(), [&seen](int x) {
            return !seen.insert(x).second;
        });
        v.erase(end, v.end());
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(EraseDuplicates_SomeDuplicates_Baseline);

static void EraseDuplicates_ManyDuplicates(benchmark::State& state)
{
    std::vector<int> vec(10000);
    for (int i = 0; i < 10000; ++i) vec[i] = i % 10;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stevensVectorLib::eraseDuplicateElements(vec));
    }
}
BENCHMARK(EraseDuplicates_ManyDuplicates);

static void EraseDuplicates_ManyDuplicates_Baseline(benchmark::State& state)
{
    std::vector<int> vec(10000);
    for (int i = 0; i < 10000; ++i) vec[i] = i % 10;

    for (auto _ : state)
    {
        state.PauseTiming();
        std::vector<int> v = vec;
        state.ResumeTiming();

        std::unordered_set<int> seen;
        auto end = std::remove_if(v.begin(), v.end(), [&seen](int x) {
            return !seen.insert(x).second;
        });
        v.erase(end, v.end());
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(EraseDuplicates_ManyDuplicates_Baseline);
