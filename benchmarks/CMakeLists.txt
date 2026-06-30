add_executable(benchmarks
    benchmark_main.cpp
    eraseAllOf.cpp
    contains.cpp
    eraseDuplicates.cpp
    sumAll.cpp
    concat.cpp
)

target_link_libraries(benchmarks
    PRIVATE
        stevensVectorLib
        benchmark::benchmark
)
