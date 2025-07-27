#include <bits/stdc++.h>
using namespace std;

int countHillValley(vector<int> &nums)
{
    int ans = 0;
    for (int i = 1; i < nums.size() - 1; i++)
    {
        int temp = nums[i];
        // searching left
        int left;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] != temp)
            {
                left = nums[j];
                break;
            }
        }
        // cout << "left: " << left;

        // searching right
        int ridx;
        int right;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] != temp)
            {
                right = nums[j];
                ridx = j;
                break;
            }
        }
        // cout << " right: " << right;

        // now i have both right and left variables defined
        if ((left > temp && right > temp) || (left < temp && right < temp))
        {
            ans++;
            // index i = index of value right
            i = ridx - 1;
        }
        // cout << " ans: " << ans << '\n';
    }
    return ans;
}

int main()
{
    vector<int> nums = {6,6,5,5,4,1};
    // vector<int> nums = {2, 4, 1, 1, 6, 5};
    cout << countHillValley(nums);
}