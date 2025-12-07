#include <bits/stdc++.h>
#define ll long long

using namespace std;
// more of a geometry problem
// this was an easy one, just had to read the question correctly, and visualize better.
void solve()
{
    // input here only
    ll w, h;
    cin >> w >> h;
    // 4 cases: choosing base as top,bottom,left,right(t,b,l,r)
    ll area = 0;
    for (ll i = 0; i < 4; i++)
    {
        ll k;
        cin >> k;
        ll first, last;
        for (ll j = 0; j < k; j++)
        {
            ll x;
            cin >> x;
            if (j == 0)
                first = x;
            if (j == k - 1)
                last = x;
        }
        ll base = last - first;
        ll height;
        if (i <= 1)
            height = h;
        else
            height = w;
        area = max(area, base * height);
    }
    cout << area << endl;
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
