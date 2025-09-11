#include <bits/stdc++.h>
#define ll long long

using namespace std;

int digits(int x)
{
    int d = 0;
    while (x > 0)
    {
        x /= 10;
        d++;
    }
    return d;
}

void solve()
{
    // input here only
    int x;
    cin >> x;
    // x concat y % (x+y) == 0
    int d = digits(x);
    ll pow10 = 1;
    for (int i = 0; i <= d; i++)
        pow10 *= 10;

    int y = pow10 - x-1;
    cout << y << endl;
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
