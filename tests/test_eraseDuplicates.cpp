#include <gtest/gtest.h>
#include "stevensVectorLib.hpp"

TEST(EraseDuplicateElementsTest, RemovesDuplicates)
{
    std::vector<int> vec = {1, 2, 1, 3, 4, 4, 5, 1};
    auto result = stevensVectorLib::eraseDuplicateElements(vec);
    EXPECT_EQ(result, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(EraseDuplicateElementsTest, PreservesOrder)
{
    std::vector<int> vec = {3, 1, 2, 1, 3};
    auto result = stevensVectorLib::eraseDuplicateElements(vec);
    EXPECT_EQ(result, std::vector<int>({3, 1, 2}));
}

TEST(EraseDuplicateElementsTest, HandlesNoDuplicates)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto result = stevensVectorLib::eraseDuplicateElements(vec);
    EXPECT_EQ(result, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(EraseDuplicateElementsTest, HandlesAllDuplicates)
{
    std::vector<int> vec = {1, 1, 1, 1};
    auto result = stevensVectorLib::eraseDuplicateElements(vec);
    EXPECT_EQ(result, std::vector<int>({1}));
}

TEST(EraseDuplicateElementsTest, HandlesEmptyVector)
{
    std::vector<int> vec;
    auto result = stevensVectorLib::eraseDuplicateElements(vec);
    EXPECT_TRUE(result.empty());
}

TEST(EraseDuplicateElementsTest, WorksWithStrings)
{
    std::vector<std::string> vec = {"a", "b", "a", "c", "b"};
    auto result = stevensVectorLib::eraseDuplicateElements(vec);
    EXPECT_EQ(result, std::vector<std::string>({"a", "b", "c"}));
}
