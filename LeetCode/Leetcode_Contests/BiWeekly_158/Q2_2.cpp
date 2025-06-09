#include<bits/stdc++.h>
using namespace std;

long long maximumProfit(vector<int>& prices, int k) {
    int n = prices.size();
    if (n <= 1 || k == 0) return 0;
    
    // For unlimited transactions (k is large)
    if (k >= n / 2) {
        long long profit = 0;
        // Greedy: capture every profitable day-to-day movement
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i-1]) {
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }
    
    // For limited k transactions, use greedy approach:
    // 1. Find all possible transactions
    // 2. Sort by profit
    // 3. Greedily select non-overlapping ones
    
    vector<pair<long long, pair<int, int>>> allTransactions;
    
    // Generate all possible profitable transactions
    for (int buy = 0; buy < n; buy++) {
        for (int sell = buy + 1; sell < n; sell++) {
            // Normal transaction: buy at 'buy', sell at 'sell'
            if (prices[sell] > prices[buy]) {
                long long profit = prices[sell] - prices[buy];
                allTransactions.push_back({profit, {buy, sell}});
            }
            
            // Short transaction: sell at 'buy', buy back at 'sell'  
            if (prices[buy] > prices[sell]) {
                long long profit = prices[buy] - prices[sell];
                allTransactions.push_back({profit, {buy, sell}});
            }
        }
    }
    
    // Sort transactions by profit in descending order
    sort(allTransactions.begin(), allTransactions.end(), 
         greater<pair<long long, pair<int, int>>>());
    
    // Greedily select non-overlapping transactions
    vector<pair<int, int>> selected;
    long long totalProfit = 0;
    int transactionCount = 0;
    
    for (const auto& transaction : allTransactions) {
        if (transactionCount >= k) break;
        
        long long profit = transaction.first;
        int start = transaction.second.first;
        int end = transaction.second.second;
        
        // Check if this transaction overlaps with any already selected
        bool canSelect = true;
        for (const auto& sel : selected) {
            // Transactions overlap if their day ranges intersect
            // [start, end] and [sel.first, sel.second] overlap if:
            // start <= sel.second && end >= sel.first
            if (start <= sel.second && end >= sel.first) {
                canSelect = false;
                break;
            }
        }
        
        if (canSelect) {
            selected.push_back({start, end});
            totalProfit += profit;
            transactionCount++;
        }
    }
    
    return totalProfit;
}