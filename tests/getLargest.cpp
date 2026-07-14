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

TEST(GetStringWithMaxCharCountTest, FindsLongestString)
{
    std::vector<std::string> vec = {"hi", "hello", "hey"};
    auto result = stevensVectorLib::getStringWithMaxCharCount(vec);
    EXPECT_EQ(result, "hello");
}

TEST(GetStringWithMaxCharCountTest, FindsFirstOnTie)
{
    std::vector<std::string> vec = {"abc", "def", "ghi"};
    auto result = stevensVectorLib::getStringWithMaxCharCount(vec);
    EXPECT_EQ(result, "abc");
}

TEST(GetStringWithMaxCharCountTest, SearchFromEnd)
{
    std::vector<std::string> vec = {"abc", "def", "ghi"};
    auto result = stevensVectorLib::getStringWithMaxCharCount(vec, "end");
    EXPECT_EQ(result, "ghi");
}

TEST(GetStringWithMaxCharCountTest, ThrowsOnEmpty)
{
    std::vector<std::string> vec;
    EXPECT_THROW(stevensVectorLib::getStringWithMaxCharCount(vec), std::invalid_argument);
}

TEST(GetStringWithMaxCharCountTest, HandlesSingleElement)
{
    std::vector<std::string> vec = {"test"};
    auto result = stevensVectorLib::getStringWithMaxCharCount(vec);
    EXPECT_EQ(result, "test");
}

TEST(GetStringWithMaxCharCountTest, ComparesByCharacterNotByte)
{
    // "мир" is 3 codepoints but 6 bytes; "hello" is 5 codepoints but only 5 bytes. A byte-length
    // comparison would (wrongly) pick "мир" as longest (6 > 5 bytes); character count correctly
    // picks "hello" (5 > 3 characters).
    std::vector<std::string> vec = {"мир", "hello"};
    auto result = stevensVectorLib::getStringWithMaxCharCount(vec);
    EXPECT_EQ(result, "hello");
}

TEST(GetStringWithMaxDisplayWidthTest, FindsWidestAsciiString)
{
    std::vector<std::string> vec = {"hi", "hello", "hey"};
    auto result = stevensVectorLib::getStringWithMaxDisplayWidth(vec);
    EXPECT_EQ(result, "hello");
}

TEST(GetStringWithMaxDisplayWidthTest, CjkOutweighsLongerCharCountAsciiString)
{
    // "世界" is 2 codepoints but double-width (4 terminal columns). "hi" is 2 codepoints,
    // single-width (2 columns). Char count ties them; display width correctly picks "世界".
    std::vector<std::string> vec = {"hi", "世界"};
    auto result = stevensVectorLib::getStringWithMaxDisplayWidth(vec);
    EXPECT_EQ(result, "世界");
}

TEST(GetStringWithMaxDisplayWidthTest, ThrowsOnEmpty)
{
    std::vector<std::string> vec;
    EXPECT_THROW(stevensVectorLib::getStringWithMaxDisplayWidth(vec), std::invalid_argument);
}
