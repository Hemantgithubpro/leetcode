#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums)
{
    // find number of 0s
    int zeroes = 0;
    for (int n : nums)
        if (n == 0)
            zeroes++;
    if (zeroes == 0)
        return nums.size() - 1;

    // intuition: 0s are checkpoints, where i can justsum the distance of pos-1 to pos+1 th 0.
    int a = 0;
    int i = 0, j = 0;
    int maxi = 0;
    while (j < nums.size())
    {
        if (nums[j] == 0 && a < 1)
            a++;
        else if (a >= 1)
        {
            i = j;
            a = 0;
        }
        j++;
        maxi = max(j - i + 1, maxi);
    }
    return maxi;
}

int main()
{
    vector<int> nums = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    cout << longestSubarray(nums);
}