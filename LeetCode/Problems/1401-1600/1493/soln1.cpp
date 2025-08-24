#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums)
{
    // find number of 0s
    int n = nums.size();
    int i = 0, zeros = 0, ans = 0;
    for (int j = 0; j < n; ++j)
    {
        if (nums[j] == 0)
            ++zeros;
        while (zeros > 1)
        {
            if (nums[i] == 0)
                --zeros;
            ++i;
        }
        ans = max(ans, j - i);
    }
    return ans;
}

int main()
{
    vector<int> nums = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    cout << longestSubarray(nums);
}