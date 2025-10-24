#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<int> f(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] <= n)
            f[v[i]]++;
    }
    vector<int> p(n + 1);
    p[0] = 0;
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] + f[i];
    int r = 1;
    for (int d = n; d >= 1; d--)
    {
        int mx = min(4 * d - 1, n);
        int mul = 0;
        if (d <= n)
            mul += f[d];
        if (2 * d <= n)
            mul += f[2 * d];
        if (3 * d <= n)
            mul += f[3 * d];
        if (p[mx] - mul <= k)
        {
            r = d;
            break;
        }
    }
    cout << r << endl;
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
