#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums)
{
    int maxi = *max_element(nums.begin(), nums.end());
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == maxi)
        {
            int j = i;
            while (j < n && nums[j] == maxi)
            {
                j++;
            }
            ans = max(ans, j - i);
            i = j;
        }
    }
    return ans;
}

int main()
{
}