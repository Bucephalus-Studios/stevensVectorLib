cmake_minimum_required(VERSION 3.16)
project(stevensVectorLib LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(stevensMathLib
    GIT_REPOSITORY https://github.com/Bucephalus-Studios/stevensMathLib.git
    GIT_TAG main
)
FetchContent_MakeAvailable(stevensMathLib)

add_library(stevensVectorLib INTERFACE)
add_library(stevensVectorLib::stevensVectorLib ALIAS stevensVectorLib)

target_include_directories(stevensVectorLib INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)
target_compile_features(stevensVectorLib INTERFACE cxx_std_17)
target_link_libraries(stevensVectorLib INTERFACE stevensMathLib)
