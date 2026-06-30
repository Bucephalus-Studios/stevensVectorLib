add_executable(tests
    test_main.cpp
    findElementIndex.cpp
    eraseAllOf.cpp
    popFront.cpp
    contains.cpp
    eraseDuplicates.cpp
    multiplyAll.cpp
    getRandomElement.cpp
    getLargest.cpp
    sumAll.cpp
    difference.cpp
    concat.cpp
    stringConversion.cpp
    reorient2D.cpp
    findMin.cpp
    uncommonElements.cpp
)

target_link_libraries(tests
    PRIVATE
        stevensVectorLib
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
