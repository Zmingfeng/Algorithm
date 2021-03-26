#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
// #include<string>

using namespace std;

string getMaxSubStr(string str1, string str2) {
    const int N = 100;
    int end = 0, maxLen = 0;
    int str1Len = str1.size(), str2Len = str2.size();
    // vector<vector<int>> dp(str1Len + 1, vector<int>(str2Len + 1, 0));
    int dp[N][N];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <N; j++) {
            dp[i][j] = 0;
        }
    }

    for(int i = 1; i <= str1Len; i++) {
        for(int j = 1; j <= str2Len; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j] > maxLen){
                    maxLen = dp[i][j];
                    end = i;
                }
            }
            
        }
    }
    return str1.substr(end - maxLen, maxLen);
}

int main() {
    cout << getMaxSubStr("abc", "abcd") << endl;
    return 0;
}