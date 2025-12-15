module;
#include <string>
#include <boost/algorithm/string.hpp>

export module game.FiveWord;

namespace wordlr::game
{
/**
 * This contains utilities for the 5 word, the basic unit of information
 * within Wordle. 5 words can also be compared with other 5 words. This also
 * has utilities to determine if a string is a valid word or valid 5 word.
 */
export class FiveWord
{
public:
    static bool properlyFormatted(const std::string& string)
    {
        const std::string kLowerCase{boost::algorithm::to_lower_copy(string)};
        return kLowerCase == string;
    }

    static bool isValidWord()
    {
        return true;
    }
};
}
