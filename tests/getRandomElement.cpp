#include <gtest/gtest.h>
#include "stevensVectorLib.hpp"

TEST(GetRandomElementTest, ReturnsElementFromVector)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::srand(42);  // Seed for reproducibility
    int element = stevensVectorLib::getRandomElement(vec);
    EXPECT_TRUE(stevensVectorLib::contains(vec, element));
}

TEST(GetRandomElementTest, WorksWithSingleElement)
{
    std::vector<int> vec = {42};
    EXPECT_EQ(stevensVectorLib::getRandomElement(vec), 42);
}

TEST(GetRandomElementTest, ThrowsOnEmptyVector)
{
    std::vector<int> vec;
    EXPECT_THROW(stevensVectorLib::getRandomElement(vec), std::invalid_argument);
}

TEST(GetRandomElementTest, WorksWithStrings)
{
    std::vector<std::string> vec = {"apple", "banana", "cherry"};
    std::srand(42);
    std::string element = stevensVectorLib::getRandomElement(vec);
    EXPECT_TRUE(stevensVectorLib::contains(vec, element));
}

TEST(GetRandomElementTest, ReturnsValidIndexMultipleTimes)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::srand(123);
    for (int i = 0; i < 100; ++i)
    {
        int element = stevensVectorLib::getRandomElement(vec);
        EXPECT_TRUE(stevensVectorLib::contains(vec, element));
    }
}
