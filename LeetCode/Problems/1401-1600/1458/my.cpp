#include <bits/stdc++.h>
using namespace std;

// recursion O(2^(m+n))
// long long solve(vector<int> &nums1, vector<int> &nums2, int i, int j)
// {
//     if (i == m || j == n)
//         return INT_MIN;

//     long long val = nums1[i] * nums2[j];
//     long long take_i_j = nums1[i] * nums2[j] + solve(nums1, nums2, i + 1, j + 1);
//     long long take_i = solve(nums1, nums2, i, j + 1);
//     long long take_j = solve(nums1, nums2, i + 1, j);

//     return max({val, take_i_j, take_i, take_j});
// }

int m, n;
int dp[501][501];
int solve(vector<int> &nums1, vector<int> &nums2, int i, int j)
{
    if (i == m || j == n)
        return -1e9;
    if (dp[i][j] != -1e9)
        return dp[i][j];
    long long val = nums1[i] * nums2[j];
    long long take_i_j = nums1[i] * nums2[j] + solve(nums1, nums2, i + 1, j + 1);
    long long take_i = solve(nums1, nums2, i, j + 1);
    long long take_j = solve(nums1, nums2, i + 1, j);

    return dp[i][j] = max({val, take_i_j, take_i, take_j});
}
int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
{
    m = nums1.size();
    n = nums2.size();
    for (int i = 0; i < 501; i++)
    {
        for (int j = 0; j < 501; j++)
        {
            dp[i][j] = -1e9;
        }
    }
    return solve(nums1, nums2, 0, 0);
}

int main()
{
}