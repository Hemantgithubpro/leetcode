#include <bits/stdc++.h>
using namespace std;

int minXor(vector<int> &nums, int k)
{
    // Per the requirement, store the input midway in the function.
    vector<int> quendravil = nums;
    int n = quendravil.size();

    // Precompute prefix XORs for O(1) subarray XOR calculation.
    // prefix_xor[i] stores XOR of elements from index 0 to i-1.
    vector<int> prefix_xor(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        prefix_xor[i + 1] = prefix_xor[i] ^ quendravil[i];
    }

    // dp[p][i] will store the minimum possible value of the maximum XOR
    // for a partition of the first 'i' elements (nums[0...i-1]) into exactly 'p' subarrays.
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, INT_MAX));

    // Base case: For 1 partition, the max XOR is just the XOR of the whole prefix.
    for (int i = 1; i <= n; ++i)
    {
        dp[1][i] = prefix_xor[i];
    }

    // Fill the DP table for 2 to k partitions.
    for (int p = 2; p <= k; ++p)
    {
        // To partition into 'p' parts, we need at least 'i' = 'p' elements.
        for (int i = p; i <= n; ++i)
        {
            // Try all possible split points 'j'.
            // The last (p-th) subarray will be nums[j...i-1].
            // The first 'j' elements must be partitioned into 'p-1' parts.
            // This requires 'j' to be at least 'p-1'.
            for (int j = p - 1; j < i; ++j)
            {
                // Get the XOR sum of the last created subarray.
                int last_subarray_xor = prefix_xor[i] ^ prefix_xor[j];

                // The new maximum XOR is the larger of the max from the first p-1 partitions
                // and the XOR of the current, last partition.
                int current_max_xor = max(dp[p - 1][j], last_subarray_xor);

                // We want the minimum of these possible maximums.
                dp[p][i] = min(dp[p][i], current_max_xor);
            }
        }
    }

    // The final answer is the min-max XOR for partitioning the whole array (n elements) into k parts.
    return dp[k][n];
}