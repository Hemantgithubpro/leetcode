#include<bits/stdc++.h>
using namespace std;

long long maximumProfit(vector<int>& prices, int k) {
    int n = prices.size();
    if (n <= 1 || k == 0) return 0;
    
    // If k is large enough, we can make unlimited transactions
    if (k >= n / 2) {
        // For each day, we can choose the best action among:
        // 1. Do nothing
        // 2. Complete any profitable normal transaction
        // 3. Complete any profitable short transaction
        vector<long long> dp(n, 0);
        
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i-1]; // do nothing
            
            // Try all possible transactions ending at day i
            for (int j = 0; j < i; j++) {
                long long prevProfit = (j > 0) ? dp[j-1] : 0;
                
                // Normal transaction: buy at j, sell at i
                if (prices[i] > prices[j]) {
                    dp[i] = max(dp[i], prevProfit + prices[i] - prices[j]);
                }
                
                // Short transaction: sell at j, buy back at i
                if (prices[j] > prices[i]) {
                    dp[i] = max(dp[i], prevProfit + prices[j] - prices[i]);
                }
            }
        }
        
        return dp[n-1];
    }
    
    // For limited k transactions, use dynamic programming
    // We need to be more careful about what constitutes a "transaction"
    // Let's define a transaction as a complete buy-sell or sell-buy cycle
    
    // dp[i][t] = maximum profit using at most t transactions up to day i
    vector<vector<long long>> dp(n, vector<long long>(k+1, 0));
    
    for (int t = 1; t <= k; t++) {
        long long maxDiff = -prices[0]; // max(dp[j-1][t-1] - prices[j]) for normal
        long long maxDiffShort = prices[0]; // max(dp[j-1][t-1] + prices[j]) for short
        
        for (int i = 1; i < n; i++) {
            // dp[i][t] is max of:
            // 1. Do nothing: dp[i-1][t]
            // 2. Complete normal transaction: maxDiff + prices[i]
            // 3. Complete short transaction: maxDiffShort - prices[i]
            
            dp[i][t] = max({
                dp[i-1][t],
                maxDiff + prices[i],      // normal transaction
                maxDiffShort - prices[i]  // short transaction
            });
            
            // Update maxDiff for next iteration
            // For normal: we want max(dp[i][t-1] - prices[i])
            // For short: we want max(dp[i][t-1] + prices[i])
            maxDiff = max(maxDiff, dp[i][t-1] - prices[i]);
            maxDiffShort = max(maxDiffShort, dp[i][t-1] + prices[i]);
        }
    }
    
    return dp[n-1][k];
}