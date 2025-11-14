#include <gtest/gtest.h>
#include "stevensVectorLib.hpp"

TEST(StringConversionTest, ConvertsVectorOfStringsToInts)
{
    std::vector<std::string> strVec = {"1", "2", "3", "4", "5"};
    auto result = stevensVectorLib::vecOfStrings_to_vecOfInts(strVec);
    EXPECT_EQ(result, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(StringConversionTest, HandlesNegativeIntegers)
{
    std::vector<std::string> strVec = {"-1", "-2", "3"};
    auto result = stevensVectorLib::vecOfStrings_to_vecOfInts(strVec);
    EXPECT_EQ(result, std::vector<int>({-1, -2, 3}));
}

TEST(StringConversionTest, HandlesEmptyVector)
{
    std::vector<std::string> strVec;
    auto result = stevensVectorLib::vecOfStrings_to_vecOfInts(strVec);
    EXPECT_TRUE(result.empty());
}

TEST(StringConversionTest, ConvertsVectorOfStringsToLongLongInts)
{
    std::vector<std::string> strVec = {"1000000000", "2000000000", "3000000000"};
    auto result = stevensVectorLib::vecOfStrings_to_vecOfLongLongInts(strVec);
    EXPECT_EQ(result, std::vector<long long>({1000000000LL, 2000000000LL, 3000000000LL}));
}

TEST(StringConversionTest, ThrowsOnInvalidString)
{
    std::vector<std::string> strVec = {"1", "not_a_number", "3"};
    EXPECT_THROW(stevensVectorLib::vecOfStrings_to_vecOfInts(strVec), std::invalid_argument);
}
