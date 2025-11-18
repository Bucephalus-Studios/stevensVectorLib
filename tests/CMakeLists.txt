cmake_minimum_required(VERSION 3.14)
project(stevensVectorLib_Tests LANGUAGES CXX)

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

# Fetch Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Create interface library for stevensVectorLib
add_library(stevensVectorLib INTERFACE)
target_include_directories(stevensVectorLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..)

# Add test executable
add_executable(tests
    test_main.cpp
    contains.cpp
    eraseAllOf.cpp
    sumAll.cpp
    multiplyAll.cpp
    stringConversion.cpp
    findElementIndex.cpp
    findMin.cpp
    getRandomElement.cpp
    concat.cpp
    uncommonElements.cpp
    getLargest.cpp
    reorient2D.cpp
    eraseDuplicates.cpp
    difference.cpp
    popFront.cpp
)

target_link_libraries(tests
    PRIVATE
        stevensVectorLib
        GTest::gtest
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
