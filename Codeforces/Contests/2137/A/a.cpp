#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    int k, x;
    cin >> k >> x;
    for (int i = 0; i < k; i++)
    {
        if ((x - 1) % 3 == 0)
        {
            ll prev_x = (x - 1) / 3;
            if (prev_x > 0 && prev_x % 2 != 0)
                x = prev_x;
            else
                x = x * 2;
        }
        else
            x = x * 2;
    }

    cout << x << endl;
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
