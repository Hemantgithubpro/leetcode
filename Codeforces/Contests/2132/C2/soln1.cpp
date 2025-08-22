#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll deal_cost(ll x)
{
    // Cost for x: 3x watermelons
    // 3x + 1 + x * (3x - 1)
    return 3 * x + 1 + x * (3 * x - 1);
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll ans = -1;
    // Try all possible number of large deals (x in 0..min(n/3, k))
    for (ll big_deals = 0; big_deals <= min(n / 3, k); ++big_deals)
    {
        ll left = n - 3 * big_deals;
        ll deals_used = big_deals + left; // left "deal A" (1 each)
        if (deals_used > k)
            continue;
        ll cost = deal_cost(big_deals) + 3 * left; // cost for big deals + cost for single (3 coins each)
        if (ans == -1 || cost < ans)
            ans = cost;
    }
    cout << ans << '\n';
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
