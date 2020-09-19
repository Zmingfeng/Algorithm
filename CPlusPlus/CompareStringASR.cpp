#include <iostream>
#include <vector>
#include <string>

using namespace std;
void split(vector<string> &result, string str, vector<char> delimiters);
int main(void)
{
    string str1, str2;
    vector<string> pro_str1, pro_str2;
    cout << "str1:";
    cin >> str1;
    cout << "str2:";
    cin >> str2;
    vector<char> c = {' '};
    split(pro_str1, str1, c);
    split(pro_str2, str2, c);
    for (auto item : pro_str1)
    {
        cout << item << endl;
    }

    return 0;
}

void split(vector<string> &result, string str, vector<char> delimiters)
{
    result.clear();
    auto start = 0;
    while (start < str.size())
    {
        //根据多个分割符分割
        auto itRes = str.find(delimiters[0], start);
        for (int i = 1; i < delimiters.size(); ++i)
        {
            auto it = str.find(delimiters[i], start);
            if (it < itRes)
                itRes = it;
        }
        if (itRes == string::npos)
        {
            result.push_back(str.substr(start, str.size() - start));
            break;
        }
        result.push_back(str.substr(start, itRes - start));
        start = itRes;
        ++start;
    }
}
