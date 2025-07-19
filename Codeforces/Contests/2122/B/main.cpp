#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    ll n;
    cin >> n;
    ll cnt = 0;

    for (int i = 0; i < n; i++)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll movedzero, movedone;
        if (b > d)
            movedzero = a;
        else
            movedzero = max(0LL, a - c);
        movedone = max(0LL, b - d);
        cnt += movedone + movedzero;
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
