#include <bits/stdc++.h>
using namespace std;

int countHillValley(vector<int> &nums)
{
    int ans = 0;
    vector<int> a;
    // a.push_back(nums[0]);
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] != nums[i + 1])
            a.push_back(nums[i]);
    }
    a.push_back(nums[nums.size() - 1]);

    for (int i = 1; i < a.size() - 1; i++)
    {
        int temp = a[i];
        // searching left
        int left;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] != temp)
            {
                left = a[j];
                break;
            }
        }
        // cout << "left: " << left;

        // searching right
        int right;
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[j] != temp)
            {
                right = a[j];
                break;
            }
        }
        // cout << " right: " << right;

        // now i have both right and left variables defined
        if ((left > temp && right > temp) || (left < temp && right < temp))
        {
            ans++;
            // index i = index of value right
        }
        // cout << " ans: " << ans << '\n';
    }

    return ans;
}

int main()
{
    vector<int> nums = {9, 6, 6, 5, 5, 4, 1, 1, 1};
    // vector<int> nums = {2, 4, 1, 1, 6, 5};
    cout << countHillValley(nums);
}