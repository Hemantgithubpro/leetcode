#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll vali(ll x, ll k)
{
    ll r = x % k;
    return min(r, (k - r) % k);
}

void solve()
{
    // input here only
    int n;
    ll k;
    cin >> n >> k;

    map<ll, int> s;
    for (int i = 0; i < n; i++)
    {
        ll val;
        cin >> val;
        s[vali(val, k)]++;
    }

    map<ll, int> t;
    for (int i = 0; i < n; i++)
    {
        ll val;
        cin >> val;
        t[vali(val, k)]++;
    }

    if (s == t)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
