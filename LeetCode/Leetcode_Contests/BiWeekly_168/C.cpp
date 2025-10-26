#include <bits/stdc++.h>
using namespace std;

long long minOperations(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 2, LLONG_MAX));
    dp[0][0] = 0;
    
    // Fill dp table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[i][j] == LLONG_MAX) continue;
            
            // Try matching nums1[i] with remaining elements in nums2
            for (int k = j; k <= n; k++) {
                long long cost = abs(nums1[i] - nums2[k]);
                dp[i + 1][k + 1] = min(dp[i + 1][k + 1], dp[i][j] + cost);
            }
        }
    }
    
    // Find minimum cost including the final append operation
    long long ans = LLONG_MAX;
    for (int i = 0; i <= n; i++) {
        if (dp[i][n] != LLONG_MAX) {
            long long cost = abs(nums1[i] - nums2[n]) + 1;
            ans = min(ans, dp[i][n] + cost);
        }
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

    vector<int> nums1 = {2};
    vector<int> nums2 = {3, 4};
    cout << minOperations(nums1, nums2) << endl;

    return 0;
}