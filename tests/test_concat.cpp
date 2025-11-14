#include <gtest/gtest.h>
#include "stevensVectorLib.hpp"

TEST(ConcatTest, ConcatenatesTwoVectors)
{
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};
    auto result = stevensVectorLib::concat(vec1, vec2);
    EXPECT_EQ(result, std::vector<int>({1, 2, 3, 4, 5, 6}));
}

TEST(ConcatTest, HandlesEmptyFirstVector)
{
    std::vector<int> vec1;
    std::vector<int> vec2 = {1, 2, 3};
    auto result = stevensVectorLib::concat(vec1, vec2);
    EXPECT_EQ(result, std::vector<int>({1, 2, 3}));
}

TEST(ConcatTest, HandlesEmptySecondVector)
{
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2;
    auto result = stevensVectorLib::concat(vec1, vec2);
    EXPECT_EQ(result, std::vector<int>({1, 2, 3}));
}

TEST(ConcatTest, HandlesBothEmpty)
{
    std::vector<int> vec1;
    std::vector<int> vec2;
    auto result = stevensVectorLib::concat(vec1, vec2);
    EXPECT_TRUE(result.empty());
}

TEST(ConcatTest, WorksWithStrings)
{
    std::vector<std::string> vec1 = {"hello", "world"};
    std::vector<std::string> vec2 = {"foo", "bar"};
    auto result = stevensVectorLib::concat(vec1, vec2);
    EXPECT_EQ(result, std::vector<std::string>({"hello", "world", "foo", "bar"}));
}

TEST(ConcatTest, PreservesOrder)
{
    std::vector<int> vec1 = {1};
    std::vector<int> vec2 = {2};
    auto result = stevensVectorLib::concat(vec1, vec2);
    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[1], 2);
}
