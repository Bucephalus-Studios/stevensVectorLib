#include <gtest/gtest.h>
#include "stevensVectorLib.hpp"

TEST(SumAllTest, SumsIntegers)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    EXPECT_EQ(stevensVectorLib::sumAll(vec, 0), 15);
}

TEST(SumAllTest, SumsWithNonZeroInit)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    EXPECT_EQ(stevensVectorLib::sumAll(vec, 10), 25);
}

TEST(SumAllTest, HandlesEmptyVector)
{
    std::vector<int> vec;
    EXPECT_EQ(stevensVectorLib::sumAll(vec, 0), 0);
    EXPECT_EQ(stevensVectorLib::sumAll(vec, 5), 5);
}

TEST(SumAllTest, SumsDoubles)
{
    std::vector<double> vec = {1.5, 2.5, 3.0};
    EXPECT_DOUBLE_EQ(stevensVectorLib::sumAll(vec, 0.0), 7.0);
}

TEST(SumAllTest, SumsNegativeNumbers)
{
    std::vector<int> vec = {-1, -2, -3};
    EXPECT_EQ(stevensVectorLib::sumAll(vec, 0), -6);
}

TEST(SumAllTest, DefaultInitValue)
{
    std::vector<int> vec = {1, 2, 3};
    EXPECT_EQ(stevensVectorLib::sumAll(vec), 6);
}
