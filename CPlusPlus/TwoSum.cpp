#include <iostream>
#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto len = nums.size();
        decltype(len) i = 0;
        for (; i < len; i++)
        {
            temp = target - nums[i];
            for(j = i + 1; j < len; j++)
            {
                if (temp == nums[j]) 
                    return {i,j};
            }
         }
    }
};