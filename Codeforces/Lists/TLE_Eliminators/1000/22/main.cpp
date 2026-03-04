#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    ll a, b;
    cin >> a >> b;

    int best = INT_MAX;
    for (int add = 0; add <= 60; add++)
    {
        ll bb = b + add;
        if (bb == 1) 
            continue;

        ll x = a;
        int ops = add;
        while (x > 0)
        {
            x /= bb;
            ops++;
        }
        best = min(best, ops);
    }

    cout << best << endl;
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
