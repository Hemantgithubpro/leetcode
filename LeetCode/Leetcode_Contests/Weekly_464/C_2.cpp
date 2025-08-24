#include <bits/stdc++.h>
using namespace std;

int dfs(int i, const vector<int> &nums, vector<int> &memo)
{
    if (memo[i] != -1)
        return memo[i];
    int n = nums.size();
    int max_val = nums[i];

    // Jump right: only j > i and nums[j] < nums[i]
    for (int j = i + 1; j < n; ++j)
    {
        if (nums[j] < nums[i])
            max_val = max(max_val, dfs(j, nums, memo));
    }
    // Jump left: only j < i and nums[j] > nums[i]
    for (int j = i - 1; j >= 0; --j)
    {
        if (nums[j] > nums[i])
            max_val = max(max_val, dfs(j, nums, memo));
    }
    memo[i] = max_val;
    return max_val;
}
vector<int> maxValue(vector<int> &nums)
{
    int n = nums.size();
    vector<int> memo(n, -1);
    vector<int> ans(n);
    for (int i = 0; i < n; ++i)
    {
        ans[i] = dfs(i, nums, memo);
    }
    return ans;
}
int main()
{
    vector<int> nums = {2, 3, 1};
    vector<int> ans = maxValue(nums);
    for (int n : ans)
    {
        cout << n << " ";
    }
}