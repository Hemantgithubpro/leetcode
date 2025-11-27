// with assistance
#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + nums[i - 1];

    vector<long long> best(k, LLONG_MAX);
    best[0] = 0;
    long long ans = LLONG_MIN;

    for (int i = 1; i <= n; i++)
    {
        int mod = i % k;
        if (best[mod] != LLONG_MAX)
            ans = max(ans, prefix[i] - best[mod]);
        best[mod] = min(best[mod], prefix[i]);
    }
    return ans;
}

int main()
{
}