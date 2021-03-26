#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

string getMaxSubSequence(string a, string b) {
    int a_size = a.size(), b_size = b.size();
    vector<vector<int>> dp(a_size + 1, vector<int>(b_size + 1, 0));
    for(int i = 1; i <= a_size; i++) {
        for(int j = 1; j <= b_size; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(a[i-1] == b[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }

    }
        string ret = "";
        for(int i = a_size, j = b_size; i > 0 && j > 0;) {
            if(a[i-1] == b[j-1]) {
                ret += a[i-1];
                i--;
                j--;
            }
            else {
                if(dp[i-1][j] > dp[i][j-1]) i--;
                else j--;
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
}

    int main() {
        cout << getMaxSubSequence("abcde", "ace") << endl;
        
        return 0;
    }