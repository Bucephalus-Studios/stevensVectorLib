#include <benchmark/benchmark.h>
#include "stevensVectorLib.hpp"
#include <vector>

static void BM_EraseAllOf_Few(benchmark::State& state)
{
    for (auto _ : state)
    {
        state.PauseTiming();
        std::vector<int> vec(10000);
        for (int i = 0; i < 10000; ++i) vec[i] = i % 100;
        state.ResumeTiming();

        stevensVectorLib::eraseAllOf(vec, 42);
    }
}
BENCHMARK(BM_EraseAllOf_Few);

static void BM_EraseAllOf_Many(benchmark::State& state)
{
    for (auto _ : state)
    {
        state.PauseTiming();
        std::vector<int> vec(10000);
        for (int i = 0; i < 10000; ++i) vec[i] = i % 2;  // Lots of duplicates
        state.ResumeTiming();

        stevensVectorLib::eraseAllOf(vec, 0);
    }
}
BENCHMARK(BM_EraseAllOf_Many);

static void BM_EraseAllOf_None(benchmark::State& state)
{
    for (auto _ : state)
    {
        state.PauseTiming();
        std::vector<int> vec(10000);
        for (int i = 0; i < 10000; ++i) vec[i] = i;
        state.ResumeTiming();

        stevensVectorLib::eraseAllOf(vec, -1);
    }
}
BENCHMARK(BM_EraseAllOf_None);
