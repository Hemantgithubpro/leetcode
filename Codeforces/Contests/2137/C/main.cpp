#include <bits/stdc++.h>
#define ll long long

using namespace std;
void solve()
{
    ll a, b;
    cin >> a >> b;
    __int128 p = a * b;

    if (p % 2 != 0)
        cout << (ll)p + 1 << endl;
    else
    {
        if (b % 2 != 0)
            cout << -1 << endl;
        else
        {
            if (p % 4 == 0)
                cout << (ll)p / 2 + 2 << endl;
            else
                cout << -1 << endl;
        }
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
