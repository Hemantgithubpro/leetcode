#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<ll> g(n);
    ll sum = 0, gmin = LLONG_MAX;
    for (int i = 0; i < n; ++i)
    {
        cin >> g[i];
        sum += g[i];
        gmin = min(gmin, g[i]);
    }
    
    cout << sum + (ll)(n - 2) * gmin << '\n';
}
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
