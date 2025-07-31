#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Edge {
    int start;
    int edge_number;
};

struct Decision {
    bool skip_current_position;
    int jump_to;
    int chosen_edge;
};

void solve() {
    int n;
    cin >> n;
    int max_position = 2 * n;

    // Build adjacency list: for each ending position, store all edges that end there
    vector<vector<Edge>> edges_ending_at(max_position + 1);
    for (int i = 1; i <= n; ++i) {
        int start, end;
        cin >> start >> end;
        edges_ending_at[end].push_back({start, i});
    }

    // DP: best_score[i] = maximum score we can achieve considering positions 1 to i
    vector<long long> best_score(max_position + 1, 0);
    vector<Decision> how_we_got_here(max_position + 1);

    for (int current_pos = 1; current_pos <= max_position; ++current_pos) {
        // Option 1: Don't take any edge ending at current_pos, just inherit previous score
        best_score[current_pos] = best_score[current_pos - 1];
        how_we_got_here[current_pos] = {true, current_pos - 1, -1};

        // Option 2: Take one of the edges ending at current_pos
        for (const auto &edge : edges_ending_at[current_pos]) {
            int edge_start = edge.start;
            int edge_length = current_pos - edge_start;
            long long score_if_we_take_this_edge = best_score[edge_start] + edge_length;

            if (score_if_we_take_this_edge > best_score[current_pos]) {
                best_score[current_pos] = score_if_we_take_this_edge;
                how_we_got_here[current_pos] = {false, edge_start, edge.edge_number};
            }
        }
    }

    // Reconstruct which edges we actually chose
    vector<int> chosen_edges;
    int current_pos = max_position;
    
    while (current_pos > 0) {
        const auto &decision = how_we_got_here[current_pos];
        
        if (decision.skip_current_position) {
            // We didn't choose any edge at this position, move to previous
            current_pos--;
        } else {
            // We chose an edge, record it and jump to where that edge started
            chosen_edges.push_back(decision.chosen_edge);
            current_pos = decision.jump_to;
        }
    }

    // Output the result
    cout << chosen_edges.size() << endl;
    for (int i = 0; i < chosen_edges.size(); ++i) {
        cout << chosen_edges[i];
        if (i < chosen_edges.size() - 1) cout << " ";
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
