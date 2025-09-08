#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    ll k, x;
    cin >> k >> x;

    ll m = (x == 0) ? k : __builtin_ctzll(x);
    ll n = k - m;

    cout << n << endl;
    ll o = x >> m;
    ll val = (o - 1) / 2;

    for (ll i = 0; i < n; i++)
    {
        if ((val >> i) & 1)
            cout << 2 << ' ';
        else
            cout << 1 << ' ';
    }
    cout << endl;
}

// void solve(ll n, vector<ll>& a){

// }

int main()
{
#ifndef oNLINE_JUDGE
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
