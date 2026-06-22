cmake_minimum_required(VERSION 3.16)
project(stevensVectorLib LANGUAGES CXX)

add_library(stevensVectorLib INTERFACE)
add_library(stevensVectorLib::stevensVectorLib ALIAS stevensVectorLib)

target_include_directories(stevensVectorLib INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)
target_compile_features(stevensVectorLib INTERFACE cxx_std_17)
