#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    // input here only
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = (a[i] > q) ? 0 : 1;
    }

    ll count_1 = 0;
    ll ways = 0;
    // a[i]<=q is valid, sliding window of size k to n.
    ll ans = 0;
    ll j = 0;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == 1)
            count_1++;
        else
        {
            if (count_1 >= k)
            {
                ll diff = count_1 - k + 1;
                ways += (diff * (diff + 1)) / 2;
            }
            count_1 = 0;
        }
    }
    if (count_1 >= k)
    {
        ll diff = count_1 - k + 1;
        ways += (diff * (diff + 1)) / 2;
    }
    cout << ways << endl;
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
