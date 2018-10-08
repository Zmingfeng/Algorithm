/****************
one:归并法
****************/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto nums1_size = nums1.size(),nums2_size = nums2.size();
        double mid_val1 = 0.0,mid_val2 = 0.0;
        decltype(nums1.size()) init_pos1 = 0,init_pos2 = 0;
        
        while (nums1_size != 0 || nums2_size != 0)
        {
            if(nums1_size !=0 && nums2_size != 0)
            {
                mid_val1 = getMidVal(nums1,init_pos1,nums1_size);
                mid_val2 = getMidVal(nums2,init_pos2,nums2_size);
                if(mid_val2 > mid_val1)
                {
                    init_pos1 += nums1_size / 2;
                    nums1_size = nums1_size / 2;
                    nums2_size = nums2_size / 2;
                }
                else if(mid_val2 < mid_val1)
                {
                    init_pos2 += nums2_size / 2;
                    nums2_size = nums2_size / 2;
                    nums1_size = nums1_size / 2;
                }
                else
                {
                    return mid_val1;
                }
                
                if(nums1_size == nums2_size && nums1_size == 1)
                {
                   return (mid_val1 + mid_val2) /2.0;
                }  
            }
            else if(nums1_size == 0) return getMidVal(nums2,init_pos2,nums2_size);
            else if(nums2_size == 0) return getMidVal(nums1,init_pos1,nums1_size);
        }
        return 0.0;
    }
    double getMidVal(vector<int> &nums,decltype(nums.size()) nums_begin,decltype(nums.size()) size)
    {
        if(size % 2) return nums[nums_begin + size/ 2] / 1.0;
        else         return (nums[nums_begin + size / 2 - 1] + nums[nums_begin + size / 2]) / 2.0;
    }
};




/*********************
two:暴力法
***********************/
static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(auto &i : nums2) nums1.push_back(i);
        sort(nums1.begin(), nums1.end());
        if(nums1.size() % 2) return nums1[nums1.size() / 2] / 1.0;
        return (nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) / 2.0;
    }
};
