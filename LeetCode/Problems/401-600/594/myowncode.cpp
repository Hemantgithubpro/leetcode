#include <bits/stdc++.h>
using namespace std;

// did it on my own, but it could be optimized.
int findLHS(vector<int> &nums)
{
    int n = nums.size();
    int len = 0;
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
    {
        um[nums[i]]++;
    }

    sort(nums.begin(), nums.end());
    for (int i = 1; i < n; i++)
    {
        if (nums[i] - nums[i - 1] == 1)
        {
            len = max(len, um[nums[i]] + um[nums[i - 1]]);
        }
    }


    return len;
}

int main()
{
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    cout << findLHS(nums);
    return 0;
}