#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;

bool check(unordered_map<char, int> rawStr, unordered_map<char, int> tempStr)
{
    for (auto &p : rawStr)
    {
        if (tempStr[p.first] < p.second)
            return false;
    }
    return true;
}

string minWindow(string s, string t)
{
    unordered_map<char, int> rawStr;
    unordered_map<char, int> tempStr;

    for (char c : t)
        rawStr[c]++;

    int n = s.size();
    int left = 0, right = -1;
    int idx = -1, maxLen = n + 1;
    while (right < n)
    {
        if (rawStr.count(s[++right]))
        {
            tempStr[s[right]]++;
        }
        while (check(rawStr, tempStr) && left <= right)
        {
            if (maxLen > right - left + 1)
            {
                maxLen = right - left + 1;
                idx = left;
            }
            if (rawStr.count(s[left]))
            {
                tempStr[s[left]]--;
            }
            left++;
        }
    }
    return idx == -1 ? string() : s.substr(idx, maxLen);
}

int main()
{
    cout << minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}