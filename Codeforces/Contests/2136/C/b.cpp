#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] <= n)
        {
            cnt[a[i]]++;
        }
    }
    vector<int> dp(n + 1, 0);
    for (int i = n; i >= 1; i--)
    {
        dp[i] = cnt[i];
        for (int j = 2 * i; j <= n; j += i)
        {
            dp[i] = max(dp[i], cnt[i] + dp[j]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
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
