#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(2, 0));
    for (int i = 0; i < n; i++)
    {
        long long cost0 = 0, cost1 = 0;
        int count0 = 0, count1 = 0;
        for (int j = 0; j < i; j++)
        {
            if (p[j] > p[i]) cost0 += (dp[j][0] == 0 ? 0 : 1);
            else cost1 += (dp[j][1] == 0 ? 0 : 1);
            
            if (dp[j][1] == 0)
                count1++;
        }
        cost0 += count1;
        if (i == 0)
        {
            dp[i][0] = 0;
            dp[i][1] = 0;
        }
        else
        {
            long long min0 = LLONG_MAX, min1 = LLONG_MAX;
            for (int j = 0; j < i; j++)
            {
                if (dp[j][0] != LLONG_MAX)
                {
                    long long cur = dp[j][0];
                    if (p[j] > p[i])
                        cur++;
                    min0 = min(min0, cur);
                }
                if (dp[j][1] != LLONG_MAX)
                {
                    long long cur = dp[j][1];
                    if (p[j] < p[i])
                        cur++;
                    min1 = min(min1, cur);
                }
            }
            dp[i][0] = min0 + cost0;
            dp[i][1] = min1 + cost1;
        }
    }
    cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
}

// void solve(ll n, vector<ll>& a){

// }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        // ll n;
        // cin>>n;
        // vector<ll> a(n);
        // for (int i = 0; i < n; i++)
        // {
        //     cin>>a[i];
        // }
        // solve(n,a);

        solve();
    }

    return 0;
}
