#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    ll n;
    cin >> n;

    ll tot = 0;
    ll curr = 1;
    ll idx = 0;

    while (n > 0)
    {
        ll digit = n % 3;
        if (digit > 0)
        {
            ll cost = 3 * curr + idx * (curr / 3);
            tot += digit * cost;
        }

        n /= 3;
        curr *= 3;
        idx++;
    }

    cout << tot << endl;
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
