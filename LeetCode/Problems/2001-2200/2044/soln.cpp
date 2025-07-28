#include <bits/stdc++.h>
using namespace std;

// O(2^n)
int countSubsets(int idx, int curror, vector<int> &nums, int maxor)
{
    if (idx == nums.size())
    {
        if (curror == maxor)
            return 1;
        return 0;
    }
    // take nums[idx]
    int takecount = countSubsets(idx + 1, curror | nums[idx], nums, maxor);

    // not take nums[idx]
    int notTakeCount = countSubsets(idx + 1, curror, nums, maxor);

    return takecount + notTakeCount;
}

int countMaxOrSubsets(vector<int> &nums)
{
    int maxor = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        maxor |= nums[i];
    }

    int curror = 0;
    return countSubsets(0, curror, nums, maxor);
    // return temp;
}

int main()
{
    vector<int> nums = {3, 2, 1, 5};
    cout << countMaxOrSubsets(nums);
    return 0;
}