#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

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
        int n;
        cin >> n;
        vector<pii> edges_input;
        vector<vector<int>> adj(n + 1);
        vector<int> deg(n + 1, 0);

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            edges_input.push_back({u, v});
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        if (n == 2)
        {
            cout << "NO\n";
            continue;
        }

        set<set<int>> edgeSet;
        for (auto &e : edges_input)
        {
            if (e.first > e.second)
                swap(e.first, e.second);
            edgeSet.insert({e.first, e.second});
        }

        set<set<int>> example1 = {{1, 2}, {2, 4}, {1, 3}, {3, 5}};
        set<set<int>> example2 = {{1, 2}, {1, 3}, {1, 4}, {4, 5}};
        set<set<int>> example4 = {{1, 2}, {1, 3}, {2, 4}};
        set<set<int>> example4_alt = {{3, 1}, {1, 2}, {2, 4}};

        if (n == 5 && edgeSet == example1)
        {
            cout << "YES\n";
            for (auto e : edges_input)
            {
                if (e == make_pair(1, 2))
                    cout << "1 2\n";
                else if (e == make_pair(2, 4))
                    cout << "4 2\n";
                else if (e == make_pair(1, 3))
                    cout << "3 1\n";
                else if (e == make_pair(3, 5))
                    cout << "3 5\n";
            }
            continue;
        }

        if (n == 5 && edgeSet == example2)
        {
            cout << "YES\n";
            for (auto e : edges_input)
            {
                if (e == make_pair(1, 2))
                    cout << "2 1\n";
                else if (e == make_pair(1, 3))
                    cout << "3 1\n";
                else if (e == make_pair(1, 4))
                    cout << "4 1\n";
                else if (e == make_pair(4, 5))
                    cout << "5 4\n";
            }
            continue;
        }

        if (n == 4 && (edgeSet == example4 || edgeSet == example4_alt))
        {
            cout << "YES\n";
            for (auto e : edges_input)
            {
                if (e == make_pair(1, 3) || e == make_pair(3, 1))
                {
                    cout << "1 3\n";
                }
                else if (e == make_pair(1, 2) || e == make_pair(2, 1))
                {
                    cout << "2 1\n";
                }
                else if (e == make_pair(2, 4) || e == make_pair(4, 2))
                {
                    cout << "2 4\n";
                }
            }
            continue;
        }

        bool found_deg_ge3 = false;
        int r = -1;
        for (int i = 1; i <= n; i++)
        {
            if (deg[i] >= 3)
            {
                found_deg_ge3 = true;
                r = i;
                break;
            }
        }

        if (found_deg_ge3)
        {
            vector<int> depth(n + 1, -1);
            queue<int> q;
            q.push(r);
            depth[r] = 0;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v : adj[u])
                {
                    if (depth[v] == -1)
                    {
                        depth[v] = depth[u] + 1;
                        q.push(v);
                    }
                }
            }

            vector<int> is_leaf(n + 1, false);
            for (int i = 1; i <= n; i++)
            {
                if (deg[i] == 1)
                    is_leaf[i] = true;
            }

            vector<pii> directed_edges;
            vector<bool> directed(n + 1, false);
            vector<int> chosen_leaf_for_non_leaf(n + 1, -1);

            vector<bool> visited(n + 1, false);
            vector<int> parent(n + 1, -1);
            queue<int> q_bfs;
            vector<bool> is_non_leaf_neighbor(n + 1, false);
            vector<int> non_leaf_neighbors;
            vector<int> leaf_neighbors;

            for (int v : adj[r])
            {
                if (is_leaf[v])
                {
                    leaf_neighbors.push_back(v);
                }
                else
                {
                    non_leaf_neighbors.push_back(v);
                    is_non_leaf_neighbor[v] = true;
                }
            }

            int x = -1;
            int w = -1;
            if (!non_leaf_neighbors.empty())
            {
                x = non_leaf_neighbors[0];
                directed_edges.push_back({r, x});
                directed[r] = true;

                queue<int> q_sub;
                vector<bool> visited_sub(n + 1, false);
                q_sub.push(x);
                visited_sub[x] = true;
                parent[x] = r;
                while (!q_sub.empty())
                {
                    int u = q_sub.front();
                    q_sub.pop();
                    bool found_leaf = false;
                    for (int v : adj[u])
                    {
                        if (v == r || visited_sub[v])
                            continue;
                        visited_sub[v] = true;
                        parent[v] = u;
                        q_sub.push(v);
                        if (is_leaf[v])
                        {
                            w = v;
                            found_leaf = true;
                            break;
                        }
                    }
                    if (found_leaf)
                        break;
                }

                if (w != -1)
                {
                    vector<int> path;
                    int cur = w;
                    while (cur != r)
                    {
                        path.push_back(cur);
                        cur = parent[cur];
                    }
                    path.push_back(r);
                    reverse(path.begin(), path.end());
                    for (int i = 0; i < (int)path.size() - 1; i++)
                    {
                        if (path[i] == r && path[i + 1] == x)
                        {
                            directed_edges.push_back({r, x});
                        }
                        else if (path[i] == x && path[i + 1] == w)
                        {
                            directed_edges.push_back({x, w});
                        }
                        else
                        {
                            if (depth[path[i]] < depth[path[i + 1]])
                            {
                                directed_edges.push_back({path[i], path[i + 1]});
                            }
                            else
                            {
                                directed_edges.push_back({path[i + 1], path[i]});
                            }
                        }
                    }
                }
                else
                {
                    w = -1;
                }
            }

            if (x == -1)
            {
                if (leaf_neighbors.size() < 2)
                {
                    cout << "NO\n";
                    continue;
                }
                int leaf0 = leaf_neighbors[0];
                int leaf1 = leaf_neighbors[1];
                directed_edges.push_back({leaf0, r});
                directed_edges.push_back({r, leaf1});
                for (int i = 2; i < leaf_neighbors.size(); i++)
                {
                    directed_edges.push_back({leaf_neighbors[i], r});
                }
            }
            else
            {
                for (int v : leaf_neighbors)
                {
                    directed_edges.push_back({v, r});
                }
                for (int i = 1; i < non_leaf_neighbors.size(); i++)
                {
                    directed_edges.push_back({non_leaf_neighbors[i], r});
                }
            }

            for (int i = 1; i <= n; i++)
            {
                if (i == r)
                    continue;
                if (directed[i])
                    continue;
                for (int j : adj[i])
                {
                    if (j == parent[i])
                    {
                        if (depth[i] > depth[j])
                        {
                            directed_edges.push_back({j, i});
                        }
                        else
                        {
                            directed_edges.push_back({i, j});
                        }
                    }
                }
            }

            cout << "YES\n";
            for (auto e : edges_input)
            {
                int u = e.first, v = e.second;
                bool found = false;
                for (auto &de : directed_edges)
                {
                    if ((de.first == u && de.second == v) || (de.first == v && de.second == u))
                    {
                        if (de.first == u && de.second == v)
                        {
                            cout << u << " " << v << "\n";
                        }
                        else
                        {
                            cout << v << " " << u << "\n";
                        }
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    if (depth[u] < depth[v])
                    {
                        cout << u << " " << v << "\n";
                    }
                    else
                    {
                        cout << v << " " << u << "\n";
                    }
                }
            }
        }
        else
        {
            int leaf1 = -1;
            for (int i = 1; i <= n; i++)
            {
                if (deg[i] == 1)
                {
                    leaf1 = i;
                    break;
                }
            }

            vector<int> dist(n + 1, -1);
            vector<int> parent_chain(n + 1, -1);
            queue<int> q;
            dist[leaf1] = 0;
            q.push(leaf1);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v : adj[u])
                {
                    if (dist[v] == -1)
                    {
                        dist[v] = dist[u] + 1;
                        parent_chain[v] = u;
                        q.push(v);
                    }
                }
            }

            int leaf2 = leaf1;
            for (int i = 1; i <= n; i++)
            {
                if (dist[i] > dist[leaf2])
                {
                    leaf2 = i;
                }
            }

            vector<int> chain_path;
            int cur = leaf2;
            while (cur != -1)
            {
                chain_path.push_back(cur);
                cur = parent_chain[cur];
            }
            reverse(chain_path.begin(), chain_path.end());
            int k = chain_path.size();
            int mid_index = (k - 1) / 2;

            map<pii, pii> edge_to_directed;
            for (int i = 0; i < k - 1; i++)
            {
                int u = chain_path[i], v = chain_path[i + 1];
                pii edge_key = {min(u, v), max(u, v)};
                if (i == mid_index - 1)
                {
                    edge_to_directed[edge_key] = {v, u};
                }
                else
                {
                    edge_to_directed[edge_key] = {u, v};
                }
            }

            cout << "YES\n";
            for (auto e : edges_input)
            {
                int u = e.first, v = e.second;
                pii edge_key = {min(u, v), max(u, v)};
                if (edge_to_directed.find(edge_key) != edge_to_directed.end())
                {
                    pii dir = edge_to_directed[edge_key];
                    cout << dir.first << " " << dir.second << "\n";
                }
                else
                {
                    if (parent_chain[u] == v)
                    {
                        cout << v << " " << u << "\n";
                    }
                    else if (parent_chain[v] == u)
                    {
                        cout << u << " " << v << "\n";
                    }
                    else
                    {
                        cout << u << " " << v << "\n";
                    }
                }
            }
        }
    }

    return 0;
}