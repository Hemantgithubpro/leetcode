#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    ll n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());
    ll k = min<ll>(n, m);
    ll ans128 = 0;
    for (ll i = 0; i < k; i++)
    {
        ans128 += a[i] * (m - i);
    }
    cout << ans128 << '\n';
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
