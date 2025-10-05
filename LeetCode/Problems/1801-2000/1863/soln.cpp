#include <bits/stdc++.h>
using namespace std;
// subset in array of size n: 2^n, Each element has two choices: in or out
// Approach 1, a little optimized, TC:2^n and not 2^n *n
int solve(vector<int> &nums, int i, int x)
{
    if (i == nums.size())
        return x;
    int include = solve(nums, i + 1, nums[i] ^ x);
    int exclude = solve(nums, i + 1, x);
    return include + exclude;
}

int subsetXORSum(vector<int> &nums)
{
    return solve(nums, 0, 0);
}

// Approach 2, O(n)
int subsetXORSum(vector<int> &nums)
{

    int total = 0;
    for (int num : nums)
    {
        total |= num;
    }
    return total << (nums.size() - 1);
}

int main()
{
}