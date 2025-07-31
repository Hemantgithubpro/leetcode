#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    vector<ll> dp(n + 1, LLONG_MAX / 2);
    vector<ll> chosen(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        ll low = p[i];
        ll high = 2LL * n - p[i];
        ll add_low = 0;
        for (int j = 1; j < i; j++)
        {
            if (chosen[j] > low)
                add_low++;
        }
        dp[i] = min(dp[i], dp[i - 1] + add_low);
        ll temp = chosen[i];
        ll add_high = 0;
        for (int j = 1; j < i; j++)
        {
            if (chosen[j] > high)
                add_high++;
        }
        if (dp[i - 1] + add_high < dp[i])
        {
            dp[i] = dp[i - 1] + add_high;
            chosen[i] = high;
        }
        else
        {
            chosen[i] = low;
        }
    }
    cout << dp[n] << endl;
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
