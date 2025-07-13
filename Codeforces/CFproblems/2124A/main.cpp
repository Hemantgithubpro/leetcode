#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (is_sorted(a.begin(), a.end()))
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    ll maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < maxi)
        {
            cout << 2 << endl
                 << maxi << " " << a[i] << endl;
            return;
        }
        maxi = max(maxi, a[i]);
    }
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
