#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int findRepeatNumber(vector<int> &nums)
{
    vector<int> temp_index(nums.size(), 0);
    for (auto i = 0; i < nums.size(); ++i)
    {
        if (temp_index[nums[i]] > 0)
        {
            return nums[i];
        }
        else
        {
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
