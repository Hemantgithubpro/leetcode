#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        if (n <= k)
            return nums[n - 1] - nums[0];

        int ans = INT_MAX;
        // sliding window of size k
        for (int i = 0; i <= n - k; i++)
        {
            int a = nums[i];
            int b = nums[i + k - 1];
            ans = min(ans, b - a);
        }
        return ans;
    }
};

int main()
{
}