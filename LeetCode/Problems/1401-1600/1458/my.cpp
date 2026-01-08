#include <bits/stdc++.h>
using namespace std;

// recursion O(2^(m+n))
int m, n;
long long solve(vector<int> &nums1, vector<int> &nums2, int i, int j)
{
    if (i == m || j == n)
        return INT_MIN;

    long long val = nums1[i] * nums2[j];
    long long take_i_j = nums1[i] * nums2[j] + solve(nums1, nums2, i + 1, j + 1);
    long long take_i = solve(nums1, nums2, i, j + 1);
    long long take_j = solve(nums1, nums2, i + 1, j);

    return max({val, take_i_j, take_i, take_j});
}
// lcs: longest common subsequence
int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
{
    m = nums1.size();
    n = nums2.size();

    return solve(nums1, nums2, 0, 0);
}

int main()
{
}