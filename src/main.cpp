import derp;
import game.FiveWord;
import word.AnotherTestWord;
import word.Word;
import game.Dictionary;
#include <string>
#include <iostream>
// Rare using moment :)
using namespace wordlr;
int main()
{
    const char kDictionaryTest[] = {
    #embed "../res/valid-wordle-words.txt"
    ,'\0'
    };
    std::cout <<kDictionaryTest;

    game::Dictionary test{};
    return 0;
}
