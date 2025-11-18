#include <gtest/gtest.h>
#include "stevensVectorLib.hpp"

TEST(MultiplyAllTest, MultipliesIntegers)
{
    std::vector<int> vec = {2, 3, 4};
    EXPECT_EQ(stevensVectorLib::multiplyAll(vec, 1), 24);
}

TEST(MultiplyAllTest, MultipliesWithNonOneInit)
{
    std::vector<int> vec = {2, 3, 4};
    EXPECT_EQ(stevensVectorLib::multiplyAll(vec, 2), 48);
}

TEST(MultiplyAllTest, HandlesEmptyVector)
{
    std::vector<int> vec;
    EXPECT_EQ(stevensVectorLib::multiplyAll(vec, 1), 1);
    EXPECT_EQ(stevensVectorLib::multiplyAll(vec, 5), 5);
}

TEST(MultiplyAllTest, MultipliesDoubles)
{
    std::vector<double> vec = {2.0, 3.0, 4.0};
    EXPECT_DOUBLE_EQ(stevensVectorLib::multiplyAll(vec, 1.0), 24.0);
}

TEST(MultiplyAllTest, HandlesZero)
{
    std::vector<int> vec = {1, 2, 0, 3};
    EXPECT_EQ(stevensVectorLib::multiplyAll(vec, 1), 0);
}

TEST(MultiplyAllTest, DefaultInitValue)
{
    std::vector<int> vec = {2, 3, 4};
    EXPECT_EQ(stevensVectorLib::multiplyAll(vec), 24);
}
