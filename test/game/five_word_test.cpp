#include <string>
#include <gtest/gtest.h>

import game.FiveWord;

namespace wordlr::game::fiveWordTest
{
TEST(FiveWord, properlyFormatted_bool)
{
    std::string invalid{"True"};
    std::string valid{"true"};
    EXPECT_FALSE(FiveWord::properlyFormatted(invalid));
    EXPECT_TRUE(FiveWord::properlyFormatted(valid));
}
}
