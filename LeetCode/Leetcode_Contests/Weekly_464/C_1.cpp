#include <bits/stdc++.h>
using namespace std;

int dfs(int i, vector<int> &nums, vector<int> &memo, vector<bool> &visited)
{
    int n = nums.size();
    if (memo[i] != -1)
        return memo[i];
    if (visited[i])
        return nums[i];
    visited[i] = true;
    if (i < 0 || i >= n)
        return INT_MIN;

    int maxi = nums[i];
    for (int j = i + 1; j < n; j++)
    {
        if (nums[j] < nums[i])
            maxi = max(maxi, dfs(j, nums, memo, visited));
    }

    for (int j = i - 1; j >= 0; j--)
    {
        if (nums[j] > nums[i])
            maxi = max(maxi, dfs(j, nums, memo, visited));
    }
    visited[i] = false;
    memo[i] = maxi;
    return maxi;
}
vector<int> maxValue(vector<int> &nums)
{
    int n = nums.size();
    vector<int> memo(n, -1);
    vector<bool> visited(n, false);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = dfs(i, nums, memo, visited);

    return ans;
}

int main()
{
}