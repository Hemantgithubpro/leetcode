#include <bits/stdc++.h>
using namespace std;

int minimumOperations(vector<int> &nums)
{
    int ans = 0, i = 0, j = 0, n = nums.size();
    unordered_map<int, bool> mp;
    while (i < n)
    {
        if (mp[nums[i]])
        {
            while (mp[nums[i]] && j < n)
            {
                ans++;
                int k = j + 3;
                while (j < n && j < k)
                {
                    mp[nums[j++]] = false;
                }
            }
            if (i < j)
            {
                i = j - 1;
            }
            else
            {
                mp[nums[i]] = true;
            }
        }
        else
        {
            mp[nums[i]] = true;
        }

        i++;
    }
    return ans;
}