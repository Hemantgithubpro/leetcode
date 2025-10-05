#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to;
    int weight;
};
vector<vector<Edge>> graph;
vector<bool> visited;
vector<int> dist;
vector<int> basis;

void add_to_basis(int val)
{
    for (int b : basis)
    {
        val = min(val, val ^ b);
    }
    if (val != 0)
    {
        basis.push_back(val);
        // Keep basis sorted for optimization
        for (int i = basis.size() - 1; i > 0 && basis[i] < basis[i - 1]; i--)
        {
            swap(basis[i], basis[i - 1]);
        }
    }
}

void dfs(int v, int current_dist)
{
    visited[v] = true;
    dist[v] = current_dist;

    for (const Edge &edge : graph[v])
    {
        int next_dist = current_dist ^ edge.weight;

        if (!visited[edge.to])
        {
            dfs(edge.to, next_dist);
        }
        else
        {
            // Found a cycle, add it to basis
            int cycle_xor = next_dist ^ dist[edge.to];
            add_to_basis(cycle_xor);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--) {
    //     // input
    //     solve();
    // }
    int N, M;
    cin >> N >> M;

    graph.resize(N + 1);
    visited.resize(N + 1, false);
    dist.resize(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }

    dfs(1, 0);

    if (!visited[N])
    {
        cout << -1 << endl;
        return 0;
    }

    // Start with the distance to N
    int result = dist[N];

    // Try to minimize using the basis
    for (int b : basis)
    {
        result = min(result, result ^ b);
    }

    cout << result << endl;

    return 0;
}
