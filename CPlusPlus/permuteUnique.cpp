#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void dfs(vector<int> &nums, vector<vector<int>> &ret, vector<int> &output, int n, int vis)
{
    if (output.size() == n)
    {
        ret.push_back(output);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if ((vis & (1 << i)) || (i > 0 && (!(vis & (1 << (i - 1)))) && nums[i] == nums[i - 1]))
            continue;
        output.push_back(nums[i]);
        vis |= (1 << i);
        dfs(nums, ret, output, n, vis);
        vis &= ~(1 << i);
        output.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    int n = nums.size();

    vector<vector<int>> ret;
    vector<int> output;
    if (n == 0)
        return ret;
    sort(nums.begin(), nums.end());
    dfs(nums, ret, output, n, 0);

    return ret;
}

int main()
{
    return 0;
}