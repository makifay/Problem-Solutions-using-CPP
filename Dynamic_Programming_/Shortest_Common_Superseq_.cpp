// "Shortest Common Supersequence"
// Length of the shortest string which has both str1 and str2 as subsequences

// Dynamic Programming Aprroach
// Using function of "Long Common SubSequence"

// l1: length of string-1, l2: length of string-2,
// Time : O(l1xl2) , nested 2 loops
// Space: O(l1xl2) , 2D-memoization table

#include <string>
#include <iostream>

// Long Common SubSequence
std::string LCS(std::string& str1, std::string& str2)
{
    int len1 = str1.size();
    int len2 = str2.size();

    // memoization table
    std::string dp[len1 + 1][len2 + 1];

    // iterate over all items
    for (int i = 0; i <= len1; ++i)
        for (int j = 0; j <= len2; ++j) {
            if (i == 0 || j == 0)
                dp[i][j] = "";
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + str1[i - 1];
            else
                dp[i][j] = dp[i][j - 1].size() > dp[i - 1][j].size() ? dp[i][j - 1] : dp[i - 1][j];
        }
    return dp[len1][len2];
}

// Shortest Common Supersequence
std::string SCS(std::string& str1, std::string& str2)
{
    std::string lcs = LCS(str1, str2);
    std::string res;

    int i1 = 0, i2 = 0;
    for (char c : lcs) {
        // adding non-LCS items in str1 and str2
        while (str1[i1] != c)
            res += str1[i1++];
        while (str2[i2] != c)
            res += str2[i2++];

        // adding LCS item once
        res += c;

        // incrementing both index
        ++i1;
        ++i2;
    }
    res += str1.substr(i1) + str2.substr(i2);
    return res;
}

// -----------------------
int main()
{
    std::string X = "CGXTPO";
    std::string Y = "GXTXAPYBOL";

    std::cout << "Length of the SCS:  " << SCS(X, Y) << std::endl;

    X = "YMMJYAUZ";
    Y = "AYMZJAWXU";

    std::cout << "Length of the SCS:  " << SCS(X, Y) << std::endl;

    return 0;
}
