#include <gtest/gtest.h>
#include "stevensVectorLib.hpp"
#include <limits>

TEST(FindElementIndexTest, FindsElementIndex)
{
    std::vector<int> vec = {10, 20, 30, 40, 50};
    EXPECT_EQ(stevensVectorLib::findElementIndex(vec, 10), 0);
    EXPECT_EQ(stevensVectorLib::findElementIndex(vec, 30), 2);
    EXPECT_EQ(stevensVectorLib::findElementIndex(vec, 50), 4);
}

TEST(FindElementIndexTest, ReturnsMaxOnNotFound)
{
    std::vector<int> vec = {10, 20, 30};
    EXPECT_EQ(stevensVectorLib::findElementIndex(vec, 99), std::numeric_limits<size_t>::max());
}

TEST(FindElementIndexTest, HandlesEmptyVector)
{
    std::vector<int> vec;
    EXPECT_EQ(stevensVectorLib::findElementIndex(vec, 1), std::numeric_limits<size_t>::max());
}

TEST(FindElementIndexTest, FindsFirstOccurrence)
{
    std::vector<int> vec = {1, 2, 3, 2, 4};
    EXPECT_EQ(stevensVectorLib::findElementIndex(vec, 2), 1);
}

TEST(FindElementIndexTest, WorksWithStrings)
{
    std::vector<std::string> vec = {"apple", "banana", "cherry"};
    EXPECT_EQ(stevensVectorLib::findElementIndex(vec, std::string("banana")), 1);
}
