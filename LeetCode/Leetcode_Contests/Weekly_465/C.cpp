#include <bits/stdc++.h>
using namespace std;

const int MAX_BITS = 20;
const int MAX_MASK = (1 << MAX_BITS) - 1;

long long solve(vector<int> &nums)
{
    vector<long long> dp(MAX_MASK + 1, 0);
    for (int x : nums)
    {
        if (x > dp[x])
            dp[x] = x;
    }

    for (int i = 0; i < MAX_BITS; i++)
    {
        for (int mask = 0; mask <= MAX_MASK; mask++)
        {
            if (mask & (1 << i))
            {
                int without = mask ^ (1 << i);
                if (dp[without] > dp[mask])
                    dp[mask] = dp[without];
            }
        }
    }

    long long ans = 0;
    for (int x : nums)
    {
        int mask = x;
        int comp = MAX_MASK & ~mask;
        if (dp[comp] != 0)
        {
            ans = max(ans, (long long)x * dp[comp]);
        }
    }
    return ans;
}

int main()
{
}