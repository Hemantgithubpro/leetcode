#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int to;
    int weight;
};

vector<vector<Edge>> graph;
vector<int> dist;
vector<int> state; // 0: unvisited, 1: in progress, 2: done
vector<int> basis;

void insert_basis(int val) {
    for (int& b : basis) {
        val = min(val, val ^ b);
    }
    if (val != 0) {
        basis.push_back(val);
        // Sort basis for optimization
        for (int i = basis.size() - 1; i > 0; i--) {
            if (basis[i] > basis[i-1]) {
                swap(basis[i], basis[i-1]);
            } else {
                break;
            }
        }
    }
}

int query_basis(int val) {
    for (int b : basis) {
        val = min(val, val ^ b);
    }
    return val;
}

void dfs(int v, int d) {
    if (state[v] == 1) {
        // Back edge - cycle found
        insert_basis(d ^ dist[v]);
        return;
    }
    
    if (state[v] == 2) {
        // Cross edge - also contributes to basis
        insert_basis(d ^ dist[v]);
        return;
    }
    
    state[v] = 1; // Mark as in progress
    dist[v] = d;
    
    for (const Edge& edge : graph[v]) {
        dfs(edge.to, d ^ edge.weight);
    }
    
    state[v] = 2; // Mark as done
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    graph.resize(N + 1);
    dist.resize(N + 1);
    state.resize(N + 1, 0);
    
    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }
    
    dfs(1, 0);
    
    if (state[N] == 0) {
        cout << -1 << endl;
    } else {
        cout << query_basis(dist[N]) << endl;
    }
    
    return 0;
}