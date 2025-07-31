// learn how to use find method in vector stl
#include <bits/stdc++.h>
using namespace std;

// my soln, not much optimal
int arithmeticTriplets(vector<int> &nums, int diff)
{
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[j] - nums[i] == diff && nums[k] - nums[j] == diff)
                    cnt++;
            }
        }
    }
    return cnt;
}

// soln: better time complexity
int arithmeticTriplets(vector<int> &nums, int diff)
{
    int ans = 0;
    for (auto i : nums)
    {
        if (find(nums.begin(), nums.end(), i + diff) != nums.end() && find(nums.begin(), nums.end(), i + 2 * diff) != nums.end())
        {
            ans++;
        }
    }
    return ans;
}
int main()
{
}