// Find the Long Common SubSequence

#include <bits/stdc++.h>
using namespace std;

string LCS(string& str1, string& str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    string dp[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; ++i)
        for (int j = 0; j <= len2; ++j) {
            if (i == 0 || j == 0) {

                dp[i][j] = "";
            }
            else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + str1[i - 1];
            }
            else {
                // check the max value
                dp[i][j] = dp[i][j - 1].size() > dp[i - 1][j].size() ? dp[i][j - 1] : dp[i - 1][j];
            }
        }
    return dp[len1][len2];
}

// ----------------------------
int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    cout << "TEST-1: " << LCS(X, Y) << endl;

    X = "XMJYAUZ";
    Y = "MZJAWXU";

    cout << "TEST-2: " << LCS(X, Y) << endl;

    return 0;
}

