#include <gtest/gtest.h>
#include "stevensVectorLib.hpp"

TEST(Reorient2DVectorTest, TransposesMatrix)
{
    std::vector<std::vector<std::string>> input = {
        {"Name", "Age", "Power"},
        {"Kelsier", "34", "Mistborn"},
        {"Marsh", "36", "Seeker"},
        {"Vin", "19", "Mistborn"}
    };

    std::vector<std::vector<std::string>> expected = {
        {"Name", "Kelsier", "Marsh", "Vin"},
        {"Age", "34", "36", "19"},
        {"Power", "Mistborn", "Seeker", "Mistborn"}
    };

    auto result = stevensVectorLib::reorient2DVector(input);
    EXPECT_EQ(result, expected);
}

TEST(Reorient2DVectorTest, HandlesEmptyVector)
{
    std::vector<std::vector<int>> input;
    auto result = stevensVectorLib::reorient2DVector(input);
    EXPECT_TRUE(result.empty());
}

TEST(Reorient2DVectorTest, HandlesSingleRow)
{
    std::vector<std::vector<int>> input = {{1, 2, 3}};
    std::vector<std::vector<int>> expected = {{1}, {2}, {3}};
    auto result = stevensVectorLib::reorient2DVector(input);
    EXPECT_EQ(result, expected);
}

TEST(Reorient2DVectorTest, HandlesSingleColumn)
{
    std::vector<std::vector<int>> input = {{1}, {2}, {3}};
    std::vector<std::vector<int>> expected = {{1, 2, 3}};
    auto result = stevensVectorLib::reorient2DVector(input);
    EXPECT_EQ(result, expected);
}

TEST(Reorient2DVectorTest, HandlesUnevenRows)
{
    std::vector<std::vector<int>> input = {
        {1, 2, 3},
        {4, 5},
        {6, 7, 8, 9}
    };

    std::vector<std::vector<int>> expected = {
        {1, 4, 6},
        {2, 5, 7},
        {3, 8},
        {9}
    };

    auto result = stevensVectorLib::reorient2DVector(input);
    EXPECT_EQ(result, expected);
}
