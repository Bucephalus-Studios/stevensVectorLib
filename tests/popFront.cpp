#include <gtest/gtest.h>
#include "stevensVectorLib.hpp"

TEST(PopFrontTest, RemovesAndReturnsFirstElement)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int result = stevensVectorLib::popFront(vec);
    EXPECT_EQ(result, 1);
    EXPECT_EQ(vec, std::vector<int>({2, 3, 4, 5}));
}

TEST(PopFrontTest, WorksWithSingleElement)
{
    std::vector<int> vec = {42};
    int result = stevensVectorLib::popFront(vec);
    EXPECT_EQ(result, 42);
    EXPECT_TRUE(vec.empty());
}

TEST(PopFrontTest, ThrowsOnEmptyVector)
{
    std::vector<int> vec;
    EXPECT_THROW(stevensVectorLib::popFront(vec), std::invalid_argument);
}

TEST(PopFrontTest, WorksWithStrings)
{
    std::vector<std::string> vec = {"first", "second", "third"};
    std::string result = stevensVectorLib::popFront(vec);
    EXPECT_EQ(result, "first");
    EXPECT_EQ(vec, std::vector<std::string>({"second", "third"}));
}

TEST(PopFrontTest, ModifiesOriginalVector)
{
    std::vector<int> vec = {10, 20, 30};
    stevensVectorLib::popFront(vec);
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], 20);
}

TEST(PopFrontTest, MultiplePopFront)
{
    std::vector<int> vec = {1, 2, 3};
    EXPECT_EQ(stevensVectorLib::popFront(vec), 1);
    EXPECT_EQ(stevensVectorLib::popFront(vec), 2);
    EXPECT_EQ(stevensVectorLib::popFront(vec), 3);
    EXPECT_TRUE(vec.empty());
}
