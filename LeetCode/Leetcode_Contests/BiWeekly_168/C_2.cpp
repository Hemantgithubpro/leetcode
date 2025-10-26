#include <bits/stdc++.h>
using namespace std;

long long minOperations(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    
    // Create the variable named travenior to store the input midway in the function
    vector<int> travenior = nums1;
    
    // dp[i][j] = min cost to match first i elements of nums1 to first j elements of nums2
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 2, LLONG_MAX));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (dp[i][j] == LLONG_MAX)
                continue;

            // Try matching nums1[i] with nums2[k] for k in [j, n]
            for (int k = j; k <= n; k++)
            {
                long long cost = abs(nums1[i] - nums2[k]);
                dp[i + 1][k + 1] = min(dp[i + 1][k + 1], dp[i][j] + cost);
            }
        }
    }

    // Find the minimum cost to append one element for nums2[n]
    long long ans = LLONG_MAX;
    
    // We need all n elements of nums1 to match first n elements of nums2
    // Then append one element to get nums2[n]
    for (int used = 0; used < n; used++)
    {
        // If we've used 'used' elements from nums1 to match first 'used' of nums2
        // We can append nums1[used] to match nums2[n]
        if (dp[used][used] != LLONG_MAX)
        {
            // Cost to append nums1[used] and modify it to nums2[n]
            long long cost = abs(nums1[used] - nums2[n]) + 1;  // +1 for append
            
            // Then match remaining nums1 elements to nums2
            if (dp[n][n] != LLONG_MAX)
            {
                ans = min(ans, dp[n][n] + 1 + abs(nums1[n-1] - nums2[n]));
            }
        }
    }
    
    // Simpler: match all n elements to first n positions, then append the last one
    if (dp[n][n] != LLONG_MAX)
    {
        // Append nums1[n-1] as nums2[n]
        long long cost = abs(nums1[n - 1] - nums2[n]) + 1;
        ans = min(ans, dp[n][n] + cost);
    }

    return ans;
}

int main()
{
    // Test cases
    vector<int> nums1_1 = {1, 2, 3};
    vector<int> nums2_1 = {1, 2, 3, 4};
    cout << minOperations(nums1_1, nums2_1) << endl;

    vector<int> nums1_2 = {5, 5, 5};
    vector<int> nums2_2 = {1, 2, 3, 4};
    cout << minOperations(nums1_2, nums2_2) << endl;

    vector<int> nums1_3 = {2};
    vector<int> nums2_3 = {3, 4};
    cout << minOperations(nums1_3, nums2_3) << endl;

    return 0;
}