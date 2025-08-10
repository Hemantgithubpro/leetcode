#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll ops;
vector<vector<int>> adj;

int dfs(int u, int p)
{
    int paths = 0;
    for (int v : adj[u])
        if (v != p)
            paths += dfs(v, u);

    if (paths == 0)
        return 1;  // Leaf node contributes one path

    ops += paths - 1;  // Need (paths-1) operations to connect paths at this node
    return 1;  // After connecting, this subtree contributes one path
}

void solve()
{
    int n;
    cin >> n;

    adj.assign(n + 1, vector<int>());
    vector<int> degree(n + 1, 0);
    ops = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    for (int i = 1; i <= n; ++i)
        if (degree[i] == n - 1)
        {
            cout << 0 << endl;
            return;
        }

    dfs(1, 0);  // No need to check return value

    cout << ops << endl;
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
