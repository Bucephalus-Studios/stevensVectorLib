# Benchmarks CMakeLists.txt
add_executable(vector_lib_benchmarks
    benchmark_main.cpp
    benchmark_contains.cpp
    benchmark_eraseAllOf.cpp
    benchmark_sumAll.cpp
    benchmark_eraseDuplicates.cpp
    benchmark_concat.cpp
)

target_link_libraries(vector_lib_benchmarks
    PRIVATE
        stevensVectorLib
        benchmark::benchmark
        benchmark::benchmark_main
)

target_include_directories(vector_lib_benchmarks PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
