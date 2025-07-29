#include <bits/stdc++.h>
using namespace std;

// i hope its not tle
vector<int> smallestSubarrays(vector<int> &nums)
{
    int n = nums.size();
    int maxor = nums[0];
    for (int i = 1; i < n; i++)
    {
        maxor |= nums[i];
    }
    // cout << maxor << '\n';
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int temp = nums[i];
        int idx = i;
        
        // Check if the single element itself equals maxor
        if (temp == maxor)
        {
            ans[i] = 1;
            continue;
        }
        
        // Expand the subarray
        while (idx + 1 < n)
        {
            idx++;
            temp |= nums[idx];
            if (temp == maxor)
            {
                ans[i] = idx - i + 1;
                break;
            }
        }
        
        // If we never found maxor, take the rest of the array
        if (temp != maxor)
        {
            ans[i] = n - i;
        }
    }

    return ans;
}

int main()
{
    // vector<int> nums = {1, 0, 2, 1, 3};
    vector<int> nums = {4, 0, 5, 6, 3, 2};
    vector<int> ans = smallestSubarrays(nums);
    for (int n : ans)
    {
        cout << n << ' ';
    }
    cout << endl;
    return 0;
}