#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> g(n);

    for (ll i = 0; i < n; ++i)
        cin >> g[i];

    sort(g.begin(), g.end());

    ll ans = 0;
    for (ll i = n - 1; i >= 0; i -= 2)
        ans += g[i];

    cout << ans << endl;
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
