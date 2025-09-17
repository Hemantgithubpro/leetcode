#include <bits/stdc++.h>
#define ll long long

using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v, x, y;
        cin >> u >> v >> x >> y;

        if (x >= y)
        {
            adj[u].push_back(v);
            deg[v]++;
        }
        else
        {
            adj[v].push_back(u);
            deg[u]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
            q.push(i);
    }

    vector<int> ord;
    ord.reserve(n);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ord.push_back(u);

        for (int v : adj[u])
        {
            deg[v]--;
            if (deg[v] == 0)
                q.push(v);
        }
    }

    vector<int> p(n + 1);
    int cv = n;
    for (int vtx : ord)
    {
        p[vtx] = cv--;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << p[i] << ' ';
    }
    cout << endl;
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
