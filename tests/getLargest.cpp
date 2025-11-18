#include <gtest/gtest.h>
#include "stevensVectorLib.hpp"

TEST(GetLargestVectorElementTest, FindsLargestVector)
{
    std::vector<std::vector<int>> vecOfVecs = {{1, 2}, {1, 2, 3, 4}, {1}};
    auto result = stevensVectorLib::getLargestVectorElement(vecOfVecs);
    EXPECT_EQ(result, std::vector<int>({1, 2, 3, 4}));
}

TEST(GetLargestVectorElementTest, FindsFirstOnTie)
{
    std::vector<std::vector<int>> vecOfVecs = {{1, 2, 3}, {4, 5, 6}};
    auto result = stevensVectorLib::getLargestVectorElement(vecOfVecs);
    EXPECT_EQ(result, std::vector<int>({1, 2, 3}));
}

TEST(GetLargestVectorElementTest, SearchFromEnd)
{
    std::vector<std::vector<int>> vecOfVecs = {{1, 2, 3}, {4, 5, 6}};
    auto result = stevensVectorLib::getLargestVectorElement(vecOfVecs, "end");
    EXPECT_EQ(result, std::vector<int>({4, 5, 6}));
}

TEST(GetLargestVectorElementTest, ThrowsOnEmpty)
{
    std::vector<std::vector<int>> vecOfVecs;
    EXPECT_THROW(stevensVectorLib::getLargestVectorElement(vecOfVecs), std::invalid_argument);
}

TEST(GetLargestVectorElementTest, HandlesSingleVector)
{
    std::vector<std::vector<int>> vecOfVecs = {{1, 2, 3}};
    auto result = stevensVectorLib::getLargestVectorElement(vecOfVecs);
    EXPECT_EQ(result, std::vector<int>({1, 2, 3}));
}

TEST(GetLongestStringElementTest, FindsLongestString)
{
    std::vector<std::string> vec = {"hi", "hello", "hey"};
    auto result = stevensVectorLib::getLongestStringElement(vec);
    EXPECT_EQ(result, "hello");
}

TEST(GetLongestStringElementTest, FindsFirstOnTie)
{
    std::vector<std::string> vec = {"abc", "def", "ghi"};
    auto result = stevensVectorLib::getLongestStringElement(vec);
    EXPECT_EQ(result, "abc");
}

TEST(GetLongestStringElementTest, SearchFromEnd)
{
    std::vector<std::string> vec = {"abc", "def", "ghi"};
    auto result = stevensVectorLib::getLongestStringElement(vec, "end");
    EXPECT_EQ(result, "ghi");
}

TEST(GetLongestStringElementTest, ThrowsOnEmpty)
{
    std::vector<std::string> vec;
    EXPECT_THROW(stevensVectorLib::getLongestStringElement(vec), std::invalid_argument);
}

TEST(GetLongestStringElementTest, HandlesSingleElement)
{
    std::vector<std::string> vec = {"test"};
    auto result = stevensVectorLib::getLongestStringElement(vec);
    EXPECT_EQ(result, "test");
}
