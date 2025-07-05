#include <bits/stdc++.h>
using namespace std;

// size at least k, so i have to negate the condition of size lower than k.
int possibleStringCount(string word, int k)
{
    const int MOD = 1e9 + 7;
    int n = word.size();

    if (n < k)
        return 0;

    vector<int> groups;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (word[i] == word[i - 1])
            count++;
        else
        {
            groups.push_back(count);
            count = 1;
        }
    }
    groups.push_back(count);

    int numGroups = groups.size();

    long long total = 1;
    for (int groupSize : groups)
    {
        total = (total * groupSize) % MOD;
    }
    if (numGroups >= k)
    {
        return total;
    }

    // dp[i] = number of ways to select exactly i characters
    vector<long long> dp(k, 0);
    dp[0] = 1; // Base case: 0 characters selected
    
    for (int freq : groups)
    {
        vector<long long> tempdp(k, 0);
        long long sum = 0;
        
        for (int i = 0; i < k; i++)
        {
            // Add the new element that enters the window
            if (i >= 1)
                sum = (sum + dp[i - 1]) % MOD;
            
            // Remove the element that exits the window
            if (i >= freq + 1)
                sum = (sum - dp[i - freq - 1] + MOD) % MOD;
            
            tempdp[i] = sum;
        }
        dp = tempdp;
    }
    
    long long invalidcount = 0;
    for (int i = 0; i < k; i++)
    {
        invalidcount = (invalidcount + dp[i]) % MOD;
    }

    return ((total - invalidcount + MOD) % MOD);
}

int main()
{
    string word = "aabbccdd";
    int k = 7;
    cout << possibleStringCount(word, k);
    return 0;
}