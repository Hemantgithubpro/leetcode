#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    // input here only
    ll n;
    cin >> n;
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll x = a - c;
        ll y = b - d;
        if (x > 0)
            sum1 += x;
        if (y > 0)
            sum2 += y;
        if (y > 0 && a > 0)
            sum2 += a;
    }
    cout << max(sum1, sum2) << endl;
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
