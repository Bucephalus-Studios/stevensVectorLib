#include <gtest/gtest.h>
#include "stevensVectorLib.hpp"

TEST(FindMinTest, FindsMinimumElement)
{
    std::vector<int> vec = {5, 2, 8, 1, 9};
    EXPECT_EQ(stevensVectorLib::findMin(vec), 1);
}

TEST(FindMinTest, FindsMinWithNegatives)
{
    std::vector<int> vec = {5, -2, 8, 1, 9};
    EXPECT_EQ(stevensVectorLib::findMin(vec), -2);
}

TEST(FindMinTest, FindsMinWithDuplicates)
{
    std::vector<int> vec = {3, 1, 1, 2};
    EXPECT_EQ(stevensVectorLib::findMin(vec), 1);
}

TEST(FindMinTest, FindsMinWithOneElement)
{
    std::vector<int> vec = {42};
    EXPECT_EQ(stevensVectorLib::findMin(vec), 42);
}

TEST(FindMinTest, ThrowsOnEmptyVector)
{
    std::vector<int> vec;
    EXPECT_THROW(stevensVectorLib::findMin(vec), std::invalid_argument);
}

TEST(FindMinTest, WorksWithDoubles)
{
    std::vector<double> vec = {3.14, 2.71, 1.41};
    EXPECT_DOUBLE_EQ(stevensVectorLib::findMin(vec), 1.41);
}
