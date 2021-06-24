// Word Break Problem
// Check whether the input string can be seperated into sequence of dictionary words

// Dynamic Programming Approach

#include <string>
#include <iostream>
#include <algorithm>

#include <vector>
#include <unordered_set>

bool wordBreak(std::string s, std::vector<std::string>& wd)
{
    // wd: word dictionary
    if (wd.size() == 0)
        return false;

    // memoization array
    std::vector<bool> DP(s.size() + 1, false);

    DP[0] = true;

    // set container holds items of word dictionary
    std::unordered_set<std::string> words;
    int maxLen = 0;

    for (const auto& word : wd) {
        words.insert(word);
        maxLen = std::max(maxLen, (int)word.size());
    }

    for (int i = 0; i <= s.size(); ++i) {
        if (DP[i]) {
            for (int j = 1; j <= maxLen && i + j <= s.size(); ++j) {
                // checking existence of sub-string
                if (words.count(s.substr(i, j))) {
                    DP[i + j] = true;
                }
            }
        }
    }

    return DP[s.size()];
}

// ----------
int main()
{
    std::vector<std::string> wd = { "The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog" };
    std::string str = "quickfoxlazydog";

    std::cout << "TEST-1: " << wordBreak(str, wd) << std::endl;

    return 0;
}
