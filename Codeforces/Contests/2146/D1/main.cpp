#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    ll ans = 0;
    for (int bit = 0; bit < 20; bit++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (i & (1 << bit))
                cnt++;
        }
        if (cnt > n / 2)
            ans += (1LL << bit) * n;
        else
            ans += 2 * (1LL << bit) * cnt;
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << ' ';
    }
    cout << endl;
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
