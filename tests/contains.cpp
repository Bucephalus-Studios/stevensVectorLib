#include <gtest/gtest.h>
#include "stevensVectorLib.hpp"
#include <string>

TEST(ContainsTest, FindsElementInVector)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    EXPECT_TRUE(stevensVectorLib::contains(vec, 3));
    EXPECT_TRUE(stevensVectorLib::contains(vec, 1));
    EXPECT_TRUE(stevensVectorLib::contains(vec, 5));
}

TEST(ContainsTest, DoesNotFindMissingElement)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    EXPECT_FALSE(stevensVectorLib::contains(vec, 6));
    EXPECT_FALSE(stevensVectorLib::contains(vec, 0));
    EXPECT_FALSE(stevensVectorLib::contains(vec, -1));
}

TEST(ContainsTest, WorksWithEmptyVector)
{
    std::vector<int> vec;
    EXPECT_FALSE(stevensVectorLib::contains(vec, 1));
}

TEST(ContainsTest, WorksWithStrings)
{
    std::vector<std::string> vec = {"hello", "world", "test"};
    EXPECT_TRUE(stevensVectorLib::contains(vec, std::string("hello")));
    EXPECT_FALSE(stevensVectorLib::contains(vec, std::string("missing")));
}

TEST(ContainsTest, WorksWithDuplicates)
{
    std::vector<int> vec = {1, 2, 2, 3, 3, 3};
    EXPECT_TRUE(stevensVectorLib::contains(vec, 2));
    EXPECT_TRUE(stevensVectorLib::contains(vec, 3));
}
