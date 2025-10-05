#include <bits/stdc++.h>
using namespace std;
// it gave tle, bcoz tc: n^2
int sumofdigits(int num)
{
    int ans = 0;
    while (num)
    {
        ans += num % 10;
        num = num / 10;
    }
    return ans;
}
int maximumSum(vector<int> &nums)
{
    int maxi = -1;
    sort(nums.begin(), nums.end());
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        for (int j = nums.size() - 1; j >= 0; j--)
        {
            if (i != j)
            {
                if (sumofdigits(nums[i]) == sumofdigits(nums[j]))
                {
                    maxi = max(nums[i] + nums[j], maxi);
                }
            }
        }
    }
    return maxi;
}

int main()
{
}