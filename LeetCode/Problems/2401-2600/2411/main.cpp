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
        while (idx < n)
        {
            // cout << "idx: " << idx << " " << "i: " << i << endl;
            temp |= nums[idx];
            if (temp == maxor)
            {
                ans[i] = idx - i + 1;
                break;
            }
            idx++;
        }
    }

    return ans;
}

int main()
{
    // vector<int> nums = {1, 0, 2, 1, 3};
    vector<int> nums = {1, 2};
    vector<int> ans = smallestSubarrays(nums);
    for (int n : ans)
    {
        cout << n << ' ';
    }
    cout << endl;
    return 0;
}