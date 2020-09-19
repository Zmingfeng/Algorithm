class Solution
{
private:
    int tryRobRecur(vector<int> &nums, int index)
    {
        int n = nums.size();
        // 边界
        if (index == n - 2 || index == n - 1)
        {
            return nums[index];
        }
        int res = -1;
        for (int i = 0; i <= n - 1; i++)
        {
            res = max(res, nums[index] + tryRobRecur(nums, index + 2));
        }
        return res;
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        //n间房
        if (n == 0)
        {
            return 0;
        }
        vector<int> memo(n, -1);
        //边界
        memo[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                memo[i] = max(memo[i], nums[j] + (j + 2 <= n - 1 ? memo[j + 2] : 0));
            }
        }
        return memo[0];
    }

private:
    int rob1(vector<int> &nums)
    {
        int n = nums.size();
        //n间房
        if (n == 0)
        {
            return 0;
        }
        vector<int> memo(n, -1);
        //边界
        memo[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                memo[i] = max(memo[i], nums[j] + (j - 2 >= 0 ? memo[j - 2] : 0));
            }
        }
        return memo[n - 1];
    }
};