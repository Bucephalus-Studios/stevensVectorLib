#include <gtest/gtest.h>
#include "stevensVectorLib.hpp"

TEST(GetUncommonElementsTest, FindsUncommonElements)
{
    std::vector<int> vec1 = {1, 2, 3, 4};
    std::vector<int> vec2 = {3, 4, 5, 6};
    auto result = stevensVectorLib::getUncommonElements(vec1, vec2);

    // Result should contain {1, 2, 5, 6}
    EXPECT_TRUE(stevensVectorLib::contains(result, 1));
    EXPECT_TRUE(stevensVectorLib::contains(result, 2));
    EXPECT_TRUE(stevensVectorLib::contains(result, 5));
    EXPECT_TRUE(stevensVectorLib::contains(result, 6));
    EXPECT_FALSE(stevensVectorLib::contains(result, 3));
    EXPECT_FALSE(stevensVectorLib::contains(result, 4));
}

TEST(GetUncommonElementsTest, HandlesNoCommonElements)
{
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};
    auto result = stevensVectorLib::getUncommonElements(vec1, vec2);
    EXPECT_EQ(result.size(), 6);
}

TEST(GetUncommonElementsTest, HandlesAllCommonElements)
{
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {1, 2, 3};
    auto result = stevensVectorLib::getUncommonElements(vec1, vec2);
    EXPECT_TRUE(result.empty());
}

TEST(GetUncommonElementsTest, HandlesEmptyFirstVector)
{
    std::vector<int> vec1;
    std::vector<int> vec2 = {1, 2, 3};
    auto result = stevensVectorLib::getUncommonElements(vec1, vec2);
    EXPECT_EQ(result, std::vector<int>({1, 2, 3}));
}

TEST(GetUncommonElementsTest, HandlesEmptySecondVector)
{
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2;
    auto result = stevensVectorLib::getUncommonElements(vec1, vec2);
    EXPECT_EQ(result, std::vector<int>({1, 2, 3}));
}

TEST(GetUncommonElementsTest, HandlesBothEmpty)
{
    std::vector<int> vec1;
    std::vector<int> vec2;
    auto result = stevensVectorLib::getUncommonElements(vec1, vec2);
    EXPECT_TRUE(result.empty());
}
