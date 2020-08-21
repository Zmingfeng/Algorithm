#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int findRepeatNumber(vector<int> &nums)
{
    // 定义一个跟原数组一样大小的数组
    vector<int> temp_index(nums.size(), 0);
    // 遍历数组
    for (auto i = 0; i < nums.size(); ++i)
    {
        // 只要元素个数不为0，再次遇到即可返回
        if (temp_index[nums[i]] > 0)
        {
            return nums[i];
        }
        else
        {
            // 对原数组中的数字进行计数
            temp_index[nums[i]] += 1;
        }
    }
}

int main(int args, char **argv)
{

    vector<int> nums{2, 3, 1, 0, 2, 5, 3};
    std::cout << findRepeatNumber(nums) << endl;
    return 0;
}
