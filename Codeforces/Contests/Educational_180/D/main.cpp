#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    // A directed tree with n-1 edges has n-1 "good pairs" from the edges themselves.
    // To get exactly n good pairs, we need exactly ONE additional good pair.
    // This single extra pair must come from a path of length 2, say x -> y -> z.
    // This creates the extra pair (x, z).
    // To ensure there are no other extra pairs (from longer paths or other length-2 paths),
    // this x -> y -> z path must be "isolated". This implies a specific "comb" structure:
    // 1. Node y must have degree 2 in the original tree (one edge to x, one to z).
    // 2. All other edges incident to x must be outgoing (x -> neighbor).
    // 3. All other edges incident to z must be incoming (neighbor -> z).
    // 4. All of these "other" neighbors of x and z must be leaves in the tree to prevent new paths.

    int center_y = -1;
    int final_x = -1, final_z = -1;

    // We iterate through all nodes to find a potential middle node 'y' of the x -> y -> z path.
    for (int y = 1; y <= n; ++y)
    {
        // Condition 1: The middle node 'y' must have degree 2.
        if (degree[y] != 2)
        {
            continue;
        }

        int x = adj[y][0];
        int z = adj[y][1];

        // The number of nodes in this comb structure is 1 (for y) + 1 (for x) + 1 (for z)
        // + (degree[x] - 1) (for x's leaf neighbors) + (degree[z] - 1) (for z's leaf neighbors).
        // This simplifies to degree[x] + degree[z] + 1.
        // For this structure to be the entire graph, this count must equal n.
        // Coincidentally, the number of good pairs in this structure is also degree[x] + degree[z] + 1.
        // So this one check validates both that the structure spans all nodes and that the good pair count is n.
        if (degree[x] + degree[z] + 1 != n)
        {
            continue;
        }

        // Condition 4: Verify all other neighbors of x and z are leaves.
        bool is_structure_valid = true;

        // Check neighbors of x
        for (int neighbor_of_x : adj[x])
        {
            if (neighbor_of_x != y && degree[neighbor_of_x] != 1)
            {
                is_structure_valid = false;
                break;
            }
        }
        if (!is_structure_valid)
            continue;

        // Check neighbors of z
        for (int neighbor_of_z : adj[z])
        {
            if (neighbor_of_z != y && degree[neighbor_of_z] != 1)
            {
                is_structure_valid = false;
                break;
            }
        }

        if (is_structure_valid)
        {
            center_y = y;
            final_x = x;
            final_z = z;
            break; // Found a valid structure, no need to search further.
        }
    }

    if (center_y != -1)
    {
        cout << "YES" << endl;
        // Orient the edges based on the found comb structure.
        int y = center_y;
        int x = final_x;
        int z = final_z;

        // Main path x -> y -> z
        cout << x << " " << y << "\n";
        cout << y << " " << z << "\n";

        // Edges branching out from x (x -> neighbor)
        for (int neighbor_of_x : adj[x])
        {
            if (neighbor_of_x != y)
            {
                cout << x << " " << neighbor_of_x << "\n";
            }
        }
        // Edges branching in to z (neighbor -> z)
        for (int neighbor_of_z : adj[z])
        {
            if (neighbor_of_z != y)
            {
                cout << neighbor_of_z << " " << z << "\n";
            }
        }
    }
    else
    {
        cout << "NO" << endl;
    }
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
