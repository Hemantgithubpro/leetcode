#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct State
{
    ll T;
    ll w;
    int u;
    int r;

    bool operator>(const State &other) const
    {
        if (T != other.T)
        {
            return T > other.T;
        }
        return w > other.w;
    }
};

struct DistValue
{
    ll T;
    ll w;

    bool operator==(DistValue &other)
    {
        return T == other.T && w == other.w;
    }
    bool operator!=(DistValue &other)
    {
        return !(*this == other);
    }
};

ll INF = LLONG_MAX;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> deg(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        deg[i] = adj[i].size();
    }

    vector<vector<DistValue>> dist(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        dist[i].resize(deg[i], {INF, INF});
    }

    priority_queue<State, vector<State>, greater<State>> pq;

    if (deg[1] > 0)
    {
        dist[1][0] = {0, 0};
        pq.push({0, 0, 1, 0});
    }
    else
    {
    }

    while (!pq.empty())
    {
        State current = pq.top();
        pq.pop();

        ll T = current.T;
        ll w = current.w;
        int u = current.u;
        int r = current.r;

        if (dist[u][r].T != T || dist[u][r].w != w)
        {
            continue;
        }

        if (deg[u] > 0)
        {
            int new_r_wait = (r + 1) % deg[u];
            ll T1 = T + 1;
            ll w1 = w + 1;

            if (T1 < dist[u][new_r_wait].T || (T1 == dist[u][new_r_wait].T && w1 < dist[u][new_r_wait].w))
            {
                dist[u][new_r_wait] = {T1, w1};
                pq.push({T1, w1, u, new_r_wait});
            }
        }

        if (deg[u] > 0)
        {
            int v = adj[u][r];
            ll T2 = T + 1;
            ll w2 = w;

            int rv = T2 % deg[v];

            if (T2 < dist[v][rv].T || (T2 == dist[v][rv].T && w2 < dist[v][rv].w))
            {
                dist[v][rv] = {T2, w2};
                pq.push({T2, w2, v, rv});
            }
        }
    }

    ll best_T = INF;
    ll best_w = INF;

    if (deg[n] > 0)
    {
        for (int r_idx = 0; r_idx < deg[n]; ++r_idx)
        {
            ll T_val = dist[n][r_idx].T;
            ll w_val = dist[n][r_idx].w;

            if (T_val < best_T)
            {
                best_T = T_val;
                best_w = w_val;
            }
            else if (T_val == best_T && w_val < best_w)
            {
                best_w = w_val;
            }
        }
    }
    else if (n == 1)
    {
        if (deg[1] == 0)
        {
            best_T = 0;
            best_w = 0;
        }
    }

    if (best_T == INF)
    {

        cout << best_T << " " << best_w << "\n";
    }
    else
    {
        cout << best_T << " " << best_w << "\n";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}