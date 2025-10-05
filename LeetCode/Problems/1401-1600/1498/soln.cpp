#include <bits/stdc++.h>
using namespace std;
int numSubseq(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    const int MOD = 1e9 + 7;

    // just a way of storing powers of 2, so that accessing is easy and not out of bounds.
    vector<int> pow2(n);
    pow2[0] = 1;
    for (int i = 1; i < n; i++)
    {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }

    int left = 0, right = n - 1;
    long long ans = 0;

    while (left <= right)
    {
        if (nums[left] + nums[right] <= target)
        {
            // All subsequences starting with nums[left] in range [left, right]
            ans = (ans + pow2[right - left]) % MOD;
            left++;
        }
        else
        {
            right--;
        }
    }

    return ans;
}

int main()
{
}