#include <bits/stdc++.h>
using namespace std;

// memoization
int countSubsets(int idx, int curror, vector<int> &nums, int maxor, vector<vector<int>> &t)
{
    if (idx == nums.size())
    {
        if (curror == maxor)
            return 1;
        return 0;
    }
    if (t[idx][curror] != -1)
        return t[idx][curror];

    // take nums[idx]
    int takecount = countSubsets(idx + 1, curror | nums[idx], nums, maxor, t);

    // not take nums[idx]
    int notTakeCount = countSubsets(idx + 1, curror, nums, maxor, t);

    return t[idx][curror] = takecount + notTakeCount;
}

int countMaxOrSubsets(vector<int> &nums)
{
    int maxor = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        maxor |= nums[i];
    }
    int n = nums.size();
    // only 2 things are changing, idx and maxor, so 2d array
    vector<vector<int>> t(n + 1, vector<int>(maxor + 1, -1));
    // (n+1)*(maxor+1)
    // TC: O(n*maxor)

    int curror = 0;
    return countSubsets(0, curror, nums, maxor, t);
}

int main()
{
    vector<int> nums = {3, 2, 1, 5};
    cout << countMaxOrSubsets(nums);
    return 0;
}