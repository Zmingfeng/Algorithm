#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        int maxV = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            maxV = max(maxV, nums[i]);
        }
        maxV = max(1, maxV);
        string prev(maxV, 'a');
        cout << prev << endl;
        for (int i = 0; i < n; i++)
        {
            string a = prev.substr(0, nums[i]);
            if (nums[i] < maxV)
            {
                char x = prev[nums[i]];
                if (x > 'a')
                    x--;
                else if (x < 'z')
                    x++;
                string b(maxV - nums[i], x);
                a = a + b;
            }
            prev = a;
            cout << a << endl;
        }
    }
    return 0;
}