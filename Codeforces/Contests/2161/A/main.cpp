#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    ll R0, X, D;
    int n;
    cin >> R0 >> X >> D >> n;
    string s;
    s.reserve(n);
    cin >> s;

    ll R = R0;
    int rated = 0;

    for (char c : s)
    {
        if (c == '1')
        {
            rated++;
            R = max(0LL, R - D);
        }
        else
        {
            if (R < X)
            {
                rated++;
                R = max(0LL, R - D);
            }
        }
    }

    cout << rated << endl;
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
