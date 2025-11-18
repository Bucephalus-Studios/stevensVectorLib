#include <gtest/gtest.h>
#include "stevensVectorLib.hpp"

TEST(EraseAllOfTest, RemovesAllOccurrences)
{
    std::vector<int> vec = {1, 2, 3, 2, 4, 2, 5};
    stevensVectorLib::eraseAllOf(vec, 2);
    EXPECT_EQ(vec, std::vector<int>({1, 3, 4, 5}));
}

TEST(EraseAllOfTest, HandlesNoMatches)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    stevensVectorLib::eraseAllOf(vec, 6);
    EXPECT_EQ(vec, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(EraseAllOfTest, HandlesEmptyVector)
{
    std::vector<int> vec;
    stevensVectorLib::eraseAllOf(vec, 1);
    EXPECT_TRUE(vec.empty());
}

TEST(EraseAllOfTest, RemovesAllElements)
{
    std::vector<int> vec = {2, 2, 2, 2};
    stevensVectorLib::eraseAllOf(vec, 2);
    EXPECT_TRUE(vec.empty());
}

TEST(EraseAllOfTest, WorksWithStrings)
{
    std::vector<std::string> vec = {"a", "b", "a", "c", "a"};
    stevensVectorLib::eraseAllOf(vec, std::string("a"));
    EXPECT_EQ(vec, std::vector<std::string>({"b", "c"}));
}
