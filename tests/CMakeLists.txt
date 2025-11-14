# Tests CMakeLists.txt
add_executable(vector_lib_tests
    test_main.cpp
    test_contains.cpp
    test_eraseAllOf.cpp
    test_sumAll.cpp
    test_multiplyAll.cpp
    test_stringConversion.cpp
    test_findElementIndex.cpp
    test_findMin.cpp
    test_getRandomElement.cpp
    test_concat.cpp
    test_uncommonElements.cpp
    test_getLargest.cpp
    test_reorient2D.cpp
    test_eraseDuplicates.cpp
    test_difference.cpp
    test_popFront.cpp
)

target_link_libraries(vector_lib_tests
    PRIVATE
        stevensVectorLib
        GTest::gtest
        GTest::gtest_main
)

target_include_directories(vector_lib_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

include(GoogleTest)
gtest_discover_tests(vector_lib_tests)
