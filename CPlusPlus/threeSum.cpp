#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

void threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int target = -nums[i];
        int left = i + 1, right = n - 1;
        while (left < right)
        {
            int temp = nums[left] + nums[right];
            if (temp < target)
                left++;
            else if (temp > target)
                right--;
            else
            {
                cout << nums[i] << ' ' << nums[left] << ' ' << nums[right] << endl;
                while (left < n - 1 && nums[++left] == nums[left - 1])
                    ;
                while (right > 0 && nums[--right] == nums[right + 1])
                    ;
            }
        }
        while (i + 1 < n && nums[i + 1] == nums[i])
            i++;
    }
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    threeSum(nums);
    return 0;
}