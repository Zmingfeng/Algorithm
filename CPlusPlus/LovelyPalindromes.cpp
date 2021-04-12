#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string n = "dsaa";
    cin >> n;
    string m(n);
    reverse(m.begin(), m.end());
    cout << n << m << endl;
    return 0;
}