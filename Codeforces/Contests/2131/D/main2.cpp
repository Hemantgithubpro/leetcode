#include <bits/stdc++.h>
#define ll long long

using namespace std;


int countPaths = 0;

int dfs(int node, int parent, vector<vector<int>> &adj) {
    int pathsFromHere = 0;
    
    for (int child : adj[node]) {
        if (child != parent) {
            pathsFromHere += dfs(child, node, adj);
        }
    }
    
    // If this is a leaf node
    if (pathsFromHere == 0) {
        return 1;
    }
    
    // Operations needed at this node = paths coming from below - 1
    countPaths += pathsFromHere - 1;
    
    // After merging all paths, this subtree contributes one path upward
    return 1;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Special case: n = 2 or star graph
    if (n == 2) {
        cout << 0 << endl;
        return;
    }
    
    // Check if there's a star node (degree n-1)
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() == n - 1) {
            cout << 0 << endl;
            return;
        }
    }
    
    // Reset global counter
    countPaths = 0;
    
    // Start DFS from any node (e.g., node 1)
    dfs(1, -1, adj);
    
    cout << countPaths << endl;
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
