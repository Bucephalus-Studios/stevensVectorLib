cmake_minimum_required(VERSION 3.14)
project(stevensVectorLib_Benchmarks LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler warnings
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Fetch Google Benchmark
include(FetchContent)
FetchContent_Declare(
    googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.8.3
)
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googlebenchmark)

# Create interface library for stevensVectorLib
add_library(stevensVectorLib INTERFACE)
target_include_directories(stevensVectorLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..)

# Add benchmark executable
add_executable(benchmarks
    benchmark_main.cpp
    contains.cpp
    eraseAllOf.cpp
    sumAll.cpp
    eraseDuplicates.cpp
    concat.cpp
)

target_link_libraries(benchmarks
    PRIVATE
        stevensVectorLib
        benchmark::benchmark
        benchmark::benchmark_main
)
