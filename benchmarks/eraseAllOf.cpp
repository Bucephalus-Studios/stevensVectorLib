#include <benchmark/benchmark.h>
#include "stevensVectorLib.hpp"
#include <vector>
#include <algorithm>

static void EraseAllOf_Few(benchmark::State& state)
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
BENCHMARK(EraseAllOf_Few);

static void EraseAllOf_Few_Baseline(benchmark::State& state)
{
    for (auto _ : state)
    {
        state.PauseTiming();
        std::vector<int> vec(10000);
        for (int i = 0; i < 10000; ++i) vec[i] = i % 100;
        state.ResumeTiming();

        vec.erase(std::remove(vec.begin(), vec.end(), 42), vec.end());
    }
}
BENCHMARK(EraseAllOf_Few_Baseline);

static void EraseAllOf_Many(benchmark::State& state)
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
BENCHMARK(EraseAllOf_Many);

static void EraseAllOf_Many_Baseline(benchmark::State& state)
{
    for (auto _ : state)
    {
        state.PauseTiming();
        std::vector<int> vec(10000);
        for (int i = 0; i < 10000; ++i) vec[i] = i % 2;
        state.ResumeTiming();

        vec.erase(std::remove(vec.begin(), vec.end(), 0), vec.end());
    }
}
BENCHMARK(EraseAllOf_Many_Baseline);

static void EraseAllOf_None(benchmark::State& state)
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
BENCHMARK(EraseAllOf_None);

static void EraseAllOf_None_Baseline(benchmark::State& state)
{
    for (auto _ : state)
    {
        state.PauseTiming();
        std::vector<int> vec(10000);
        for (int i = 0; i < 10000; ++i) vec[i] = i;
        state.ResumeTiming();

        vec.erase(std::remove(vec.begin(), vec.end(), -1), vec.end());
    }
}
BENCHMARK(EraseAllOf_None_Baseline);
