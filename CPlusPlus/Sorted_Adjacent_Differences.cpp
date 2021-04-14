#include <iostream>
#include <vector>
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
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        int left = (n - 1) / 2, right = left + 1;
        if (n % 2)
        {
            left = n / 2;
            right = n / 2;
        }

        while (left >= 0 && right < n)
        {
            if (left == right)
            {
                cout << nums[left] << ' ';
            }
            else
            {
                cout << nums[left] << ' ';
                cout << nums[right] << ' ';
            }
            left--;
            right++;
        }
        cout << endl;
    }
    return 0;
}