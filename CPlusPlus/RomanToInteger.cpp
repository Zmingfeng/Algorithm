#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int romanToInt(string s) {
    int output_number = 0;
    map<char, int> RomanToInteger{
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    cout << s[2] << endl;
    for (int i = 0; i < s.length() - 1; ++i){
        RomanToInteger[s[i+1]] < RomanToInteger[s[i]] ? output_number += RomanToInteger[s[i]] : output_number -= RomanToInteger[s[i]];
    }
    output_number += RomanToInteger[s[s.length() -1]];
    return output_number;
}

int main(int args, char **argv){

    string roman;
    cout << "Please input roman number:";
    cin >> roman;
    cout << romanToInt(roman) << endl;
    return 0;
}
