#include <bits/stdc++.h>
using namespace std;

int largestPerimeter(vector<int> &nums)
{
    // a+b<c a+c<b b+c<a
    int n = nums.size();
    int ans = 0;
    sort(nums.begin(), nums.end(), greater<int>());
    for (int i = 0; i < n - 2; i++)
    {
        if (nums[i] >= nums[i + 1] + nums[i + 2])
            continue;
        if (i > n - 2)
            return 0;
        ans = max(ans, nums[i] + nums[i + 1] + nums[i + 2]);
    }
    return ans;
}

int main()
{
}