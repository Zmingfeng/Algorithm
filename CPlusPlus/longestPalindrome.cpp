#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxLen = 1;
    int Idx = 0;

    for (int i = 0; i < n; i++)
        dp[i][i] = true;
    for (int l = 1; l < n; l++)
    {
        for (int i = 0; i < n - l; i++)
        {
            if (l > 1)
            {
                dp[i][i + l] = (s[i] == s[i + l] && dp[i + 1][i + l - 1]);
            }
            else
            {
                dp[i][i + l] = (s[i] == s[i + l]);
            }
            if (dp[i][i + l] && l + 1 > maxLen)
            {
                maxLen = l + 1;
                Idx = i;
            }
        }
    }
    return s.substr(Idx, maxLen);
}

int main()
{
    return 0;
}