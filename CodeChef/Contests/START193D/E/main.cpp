#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int N;
    cin >> N;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // BFS helper to compute distances
    auto bfs = [&](int src, vector<int> &dist)
    {
        dist.assign(N + 1, -1);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                if (dist[v] < 0)
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    };
    // find tree diameter endpoints A and B
    vector<int> d0;
    bfs(1, d0);
    int A = 1;
    for (int i = 1; i <= N; i++)
        if (d0[i] > d0[A])
            A = i;
    vector<int> dA;
    bfs(A, dA);
    int B = A;
    for (int i = 1; i <= N; i++)
        if (dA[i] > dA[B])
            B = i;
    vector<int> dB;
    bfs(B, dB);
    // compute eccentricities and sort descending
    vector<pair<int, int>> ecc;
    ecc.reserve(N);
    for (int i = 1; i <= N; i++)
        ecc.emplace_back(max(dA[i], dB[i]), i);
    sort(ecc.begin(), ecc.end(), greater<>());
    vector<int> order(N);
    for (int i = 0; i < N; i++)
        order[i] = ecc[i].second;
    vector<char> removed(N + 1, 0), vis(N + 1);
    long long totalPairs = 1LL * N * (N + 1) / 2;
    long long score = 0;
    // compute contributions C[k] for k=1..N
    for (int k = 0; k < N; k++)
    {
        removed[order[k]] = 1;
        fill(vis.begin(), vis.end(), 0);
        long long sumCompTerm = 0;
        for (int v = 1; v <= N; v++)
        {
            if (!removed[v] && !vis[v])
            {
                int s = 0;
                queue<int> q;
                vis[v] = 1;
                q.push(v);
                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    s++;
                    for (int to : adj[u])
                    {
                        if (!removed[to] && !vis[to])
                        {
                            vis[to] = 1;
                            q.push(to);
                        }
                    }
                }
                sumCompTerm += 1LL * s * (s + 1) / 2;
            }
        }
        long long C = totalPairs - sumCompTerm;
        score += C;
    }
    cout << score;
    cout << '\n';
}

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
        solve();
    }

    return 0;
}
