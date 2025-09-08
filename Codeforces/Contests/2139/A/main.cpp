#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;
    int cnt = 0;
    if (x != y)
    {
        // lcm of x and y, so either 1 or 2
        if (x > y)
        {
            if (x % y == 0)
                cnt = 1;
            else
                cnt = 2;
        }
        else
        {
            if (y % x == 0)
                cnt = 1;
            else
                cnt = 2;
        }
    }
    cout << cnt << endl;
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
