#include <iostream>
#include <string>
#include <algorithm>

using namespace std;



    bool isStringOfTracts(const string s,decltype(s.size()) i,decltype(s.size()) j)
    {
        while (j - i > 1) if(s[i++] != s[j--]) return false;
        return true;
    }

    string longestPalindrome(string s) {
        string subString;
        decltype(s.size()) len = 0,flag = 0;
        for(decltype(s.size()) i = 0; i < s.size() - 1;i++)
        {
            for(decltype(s.size()) j = i + 1; j < s.size(); j++)
                if(isStringOfTracts(s,i,j))
                {           
                    flag = i - 1;
                    len = max(len,j - i + 1);
                }
        }
		cout << flag << " " << len << endl;
        for(int i = flag;i < flag + len; i++) 
		{
			cout << s[i] << endl;
			subString.push_back(s[i]);
		}
		cout << subString << endl;
        return subString;
    }

	int main()
	{
		cout << longestPalindrome("babad") << endl;
		return 0;
	}

