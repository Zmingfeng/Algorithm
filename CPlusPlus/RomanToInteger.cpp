#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;


int main(int args, string *argv[]){

    string roman;
    cout << 'Please input roman number:';
    cin >> roman;
    cout << endl;
    cout << romanToInt(roman) << endl;
    return 0;
}
int romanToInt(string s) {
    int output_number = 0;
    map<char, int> RomanToInteger{
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    for (int i = 0; i++; i < s.length()){
        switch (s[i] + s[i+1]){
            case 'IV': 
            case 'IX':
            case 'XL':
            case 'XC':
            case 'CD':
            case 'CM':
                output_number += int(RomanToInteger[s[i+1]]) - int(RomanToInteger[s[i]]);
                break;
            default:
                output_number += int(RomanToInteger[s[i+1]]);
                break;
        }       
    }
    return output_number;
}