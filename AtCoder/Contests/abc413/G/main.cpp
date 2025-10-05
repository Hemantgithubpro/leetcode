#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to, rev;
    int cap;
    int cost;
};

class MinCostFlow
{
    int N;
    vector<vector<Edge>> graph;
    vector<int> potential, dist, prev_vertex, prev_edge;

public:
    MinCostFlow(int n) : N(n), graph(n), potential(n), dist(n), prev_vertex(n), prev_edge(n) {}

    void addEdge(int from, int to, int lower, int upper, int cost)
    {
        // lower is used for demand adjustment, we only store capacity here
        graph[from].push_back({to, (int)graph[to].size(), upper - lower, cost});
        graph[to].push_back({from, (int)graph[from].size() - 1, 0, -cost});
    }

    bool solveMinCostFlow(int source, int sink, int &totalCost)
    {
        const int INF = 1e9;
        totalCost = 0;

        while (true)
        {
            fill(dist.begin(), dist.end(), INF);
            dist[source] = 0;

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, source});

            while (!pq.empty())
            {
                pair<int, int> p = pq.top();
                pq.pop();
                int curr_dist = p.first;
                int u = p.second;
                if (curr_dist > dist[u])
                    continue;

                for (int i = 0; i < graph[u].size(); i++)
                {
                    Edge &e = graph[u][i];
                    if (e.cap > 0)
                    {
                        int cost_through_u = dist[u] + e.cost + potential[u] - potential[e.to];
                        if (cost_through_u < dist[e.to])
                        {
                            dist[e.to] = cost_through_u;
                            prev_vertex[e.to] = u;
                            prev_edge[e.to] = i;
                            pq.push({dist[e.to], e.to});
                        }
                    }
                }
            }

            if (dist[sink] == INF)
                break;

            for (int i = 0; i < N; i++)
            {
                if (dist[i] < INF)
                    potential[i] += dist[i];
            }

            int flow = INF;
            for (int v = sink; v != source; v = prev_vertex[v])
            {
                int u = prev_vertex[v];
                int edge_index = prev_edge[v];
                flow = min(flow, graph[u][edge_index].cap);
            }

            for (int v = sink; v != source; v = prev_vertex[v])
            {
                int u = prev_vertex[v];
                int edge_index = prev_edge[v];
                graph[u][edge_index].cap -= flow;
                graph[v][graph[u][edge_index].rev].cap += flow;
                totalCost += flow * graph[u][edge_index].cost;
            }
        }

        return true;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[i] = make_pair(u, v);
    }

    int S = M + N;
    int T = M + N + 1;
    MinCostFlow mcf(M + N + 2);

    // Edge node: i = 0 to M-1
    for (int i = 0; i < M; i++)
    {
        mcf.addEdge(S, i, 0, 1, 1); // edge costs 1
    }

    for (int i = 0; i < M; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        mcf.addEdge(i, M + u, 0, 1, 0);
        mcf.addEdge(i, M + v, 0, 1, 0);
    }

    for (int v = 0; v < N; v++)
    {
        int lower = A[v] % 2;
        int upper = A[v];
        mcf.addEdge(M + v, T, lower, upper, 0);
    }

    int answerCost;
    bool feasible = mcf.solveMinCostFlow(S, T, answerCost);

    if (feasible)
        cout << answerCost << "\n";
    else
        cout << -1 << "\n";

    return 0;
}
