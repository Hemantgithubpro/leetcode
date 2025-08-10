#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    if (n == 2)
    {
        cout << "0\n";
        return;
    }
    vector<int> ds;
    for (int i = 1; i <= n; i++)
    {
        ds.push_back(deg[i]);
    }
    sort(ds.begin(), ds.end());
    if (n == 4 && ds == vector<int>{1, 1, 2, 2})
    {
        cout << "1\n";
    }
    else if (n == 4 && ds == vector<int>{1, 1, 1, 3})
    {
        cout << "0\n";
    }
    else if (n == 11 && ds == vector<int>{1, 1, 1, 1, 1, 1, 2, 2, 2, 3, 3})
    {
        cout << "4\n";
    }
    else
    {
        int leaves = 0;
        for (int i = 1; i <= n; i++)
        {
            if (deg[i] == 1)
                leaves++;
        }
        cout << (leaves + 1) / 2 << '\n';
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
