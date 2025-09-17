#include <bits/stdc++.h>
#define ll long long

using namespace std;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> b(k);
    for (ll i = 0; i < k; i++)
        cin >> b[i];

    sort(a.begin(), a.end(), greater<ll>());

    ll total = 0;
    for (ll i = 0; i < n; i++)
        total += a[i];

    sort(b.begin(), b.end());

    ll used = 0;
    for (ll i = 0; i < k && used < n; i++)
    {
        if (used + b[i] <= n)
        {
            total -= a[used + b[i] - 1];
            used += b[i];
        }
    }

    cout << total << endl;
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
