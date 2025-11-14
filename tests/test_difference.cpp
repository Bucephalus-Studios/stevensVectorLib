#include <gtest/gtest.h>
#include "stevensVectorLib.hpp"

TEST(DifferenceTest, RemovesMatchingElements)
{
    std::vector<int> vec1 = {1, 1, 2, 3, 4, 5};
    std::vector<int> vec2 = {1, 3, 5};
    auto result = stevensVectorLib::difference(vec1, vec2);
    EXPECT_EQ(result, std::vector<int>({1, 2, 4}));
}

TEST(DifferenceTest, HandlesNoMatches)
{
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};
    auto result = stevensVectorLib::difference(vec1, vec2);
    EXPECT_EQ(result, std::vector<int>({1, 2, 3}));
}

TEST(DifferenceTest, HandlesAllMatches)
{
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {1, 2, 3};
    auto result = stevensVectorLib::difference(vec1, vec2);
    EXPECT_TRUE(result.empty());
}

TEST(DifferenceTest, HandlesEmptyFirstVector)
{
    std::vector<int> vec1;
    std::vector<int> vec2 = {1, 2, 3};
    auto result = stevensVectorLib::difference(vec1, vec2);
    EXPECT_TRUE(result.empty());
}

TEST(DifferenceTest, HandlesEmptySecondVector)
{
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2;
    auto result = stevensVectorLib::difference(vec1, vec2);
    EXPECT_EQ(result, std::vector<int>({1, 2, 3}));
}

TEST(DifferenceTest, RemovesOneOccurrencePerMatch)
{
    std::vector<int> vec1 = {1, 1, 1, 2, 3};
    std::vector<int> vec2 = {1, 1};
    auto result = stevensVectorLib::difference(vec1, vec2);
    EXPECT_EQ(result, std::vector<int>({1, 2, 3}));
}
