#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

bool check(vector<vector<int>> &arr, int mid, int k, int n)
{
    int i = n - 1;
    int j = 0;
    int num = 0;
    while (i >= 0 && j < n)
    {
        if (arr[i][j] <= mid)
        {
            num += i + 1;
            j++;
        }
        else
        {
            i--;
        }
    }
    return num >= k;
}

int kthSmallest(vector<vector<int>> &arr, int k)
{
    int n = arr.size();
    if (n == 0)
        return -1;
    int left = arr[0][0], right = arr[n - 1][n - 1];
    while (left < right)
    {
        int mid = left + ((right - left) >> 1);
        if (check(arr, mid, k, n))
        {
            right = mid;
        }
        else
            left = mid + 1;
    }
    return left;
}

int main()
{
    vector<vector<int>> arr = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    cout << kthSmallest(arr, 8) << endl;
    return 0;
}