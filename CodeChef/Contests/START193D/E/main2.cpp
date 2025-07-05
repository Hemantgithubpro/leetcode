#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 2005;
vector<int> adj[MAXN];
int n;
int dist[MAXN][MAXN];
int parent[MAXN][MAXN];
int sz[MAXN];

// BFS from each node to compute all-pairs shortest paths and parent pointers
void bfs(int start_node)
{
    for (int i = 1; i <= n; ++i)
    {
        dist[start_node][i] = -1;
        parent[start_node][i] = 0;
    }
    vector<int> q;
    q.push_back(start_node);
    dist[start_node][start_node] = 0;

    int head = 0;
    while (head < q.size())
    {
        int u = q[head++];
        for (int v : adj[u])
        {
            if (dist[start_node][v] == -1)
            {
                dist[start_node][v] = dist[start_node][u] + 1;
                parent[start_node][v] = u;
                q.push_back(v);
            }
        }
    }
}

// DFS to compute subtree size, avoiding parent p
int get_subtree_size(int u, int p)
{
    sz[u] = 1;
    for (int v : adj[u])
    {
        if (v != p)
        {
            sz[u] += get_subtree_size(v, u);
        }
    }
    return sz[u];
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        adj[i].clear();
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Precomputation
    for (int i = 1; i <= n; ++i)
    {
        bfs(i);
    }

    // Greedy permutation: leaves first
    vector<int> p;
    vector<int> leaves;
    vector<int> non_leaves;
    for (int i = 1; i <= n; ++i)
    {
        if (adj[i].size() == 1 && n > 1)
        { // A single node tree has no leaves in this context
            leaves.push_back(i);
        }
        else
        {
            non_leaves.push_back(i);
        }
    }
    if (n == 1)
        p.push_back(1);

    for (int leaf : leaves)
        p.push_back(leaf);
    for (int non_leaf : non_leaves)
        p.push_back(non_leaf);

    long long total_score = 0;
    vector<int> S;
    int diam_a = -1, diam_b = -1;

    for (int k = 1; k <= n; ++k)
    {
        int w = p[k - 1];
        S.push_back(w);
        long long cost_k = 0;

        if (k == 1)
        {
            diam_a = w;
            diam_b = w;
            cost_k = n;
        }
        else
        {
            // Update diameter of the minimal spanning subtree for S
            int d_ab = dist[diam_a][diam_b];
            int d_aw = dist[diam_a][w];
            int d_bw = dist[diam_b][w];

            if (d_aw > d_ab && d_aw >= d_bw)
            {
                diam_b = w;
            }
            else if (d_bw > d_ab && d_bw > d_aw)
            {
                diam_a = w;
            }

            // Check if T_S is a path
            bool is_path = true;
            for (int node : S)
            {
                if (dist[diam_a][node] + dist[node][diam_b] != dist[diam_a][diam_b])
                {
                    is_path = false;
                    break;
                }
            }

            if (is_path)
            {
                // Get sizes of components hanging off the diameter endpoints
                int p_a = parent[diam_b][diam_a];
                long long size_a = (p_a == 0) ? n : get_subtree_size(diam_a, p_a);

                int p_b = parent[diam_a][diam_b];
                long long size_b = (p_b == 0) ? n : get_subtree_size(diam_b, p_b);

                cost_k = size_a * size_b;
            }
            else
            {
                cost_k = 0;
            }
        }
        total_score += cost_k;
    }

    cout << total_score << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}