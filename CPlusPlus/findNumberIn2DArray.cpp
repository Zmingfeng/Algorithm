#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool findNumberIn2DArray(vector<vector<int>> &arr, int target)
{
    int m = arr.size();
    if (m == 0)
        return -1;
    int n = arr[0].size();
    int col = n - 1, row = 0;
    while (col >= 0 && row < n)
    {
        if (arr[row][col] == target)
            return true;
        else if (arr[row][col] > target)
            col--;
        else
            row++;
    }
    return false;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    int target = 20;
    cout << findNumberIn2DArray(arr, target) << endl;
    return 0;
}