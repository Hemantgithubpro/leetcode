#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Disjoint Set Union (DSU) class for tracking connected components.
class DSU
{
    vector<int> parent;
    int components;

public:
    DSU(int n)
    {
        parent.resize(n);
        // Initially, each node is its own parent.
        iota(parent.begin(), parent.end(), 0);
        components = n;
    }

    // Find the representative (root) of the set containing element i, with path compression.
    int find(int i)
    {
        if (parent[i] == i)
        {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    // Unite the sets containing elements i and j.
    void unite(int i, int j)
    {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j)
        {
            parent[root_i] = root_j;
            components--;
        }
    }

    // Check if two elements are already in the same component.
    bool is_connected(int i, int j)
    {
        return find(i) == find(j);
    }

    // Get the current number of disjoint components.
    int get_components() const
    {
        return components;
    }
};

class Solution
{
public:
    /**
     * @brief Checks if a spanning tree with minimum strength `stability` can be formed.
     * @param stability The target minimum strength for all edges in the ST.
     * @param n The number of nodes.
     * @param edges The list of all available edges.
     * @param k The maximum number of upgrades allowed.
     * @return True if such a spanning tree is possible, false otherwise.
     */
    bool can_achieve_stability(long long stability, int n, const vector<vector<int>> &edges, int k)
    {
        DSU dsu(n);
        int upgrades_used = 0;

        // 1. Process all mandatory edges.
        // They must be included and their strength must meet the target stability.
        for (const auto &edge : edges)
        {
            if (edge[3] == 1)
            { // musti == 1
                if (edge[2] < stability)
                {
                    return false; // Mandatory edge is too weak.
                }
                if (dsu.is_connected(edge[0], edge[1]))
                {
                    return false; // Mandatory edges form a cycle.
                }
                dsu.unite(edge[0], edge[1]);
            }
        }

        // 2. Greedily use optional edges that do NOT require an upgrade.
        for (const auto &edge : edges)
        {
            if (edge[3] == 0 && edge[2] >= stability)
            { // musti == 0
                if (!dsu.is_connected(edge[0], edge[1]))
                {
                    dsu.unite(edge[0], edge[1]);
                }
            }
        }

        // 3. If not fully connected, use optional edges that DO require an upgrade.
        if (dsu.get_components() > 1)
        {
            for (const auto &edge : edges)
            {
                if (edge[3] == 0 && (long long)edge[2] * 2 >= stability && edge[2] < stability)
                {
                    if (!dsu.is_connected(edge[0], edge[1]))
                    {
                        if (upgrades_used < k)
                        {
                            dsu.unite(edge[0], edge[1]);
                            upgrades_used++;
                        }
                        else
                        {
                            break; // No more upgrades left.
                        }
                    }
                }
            }
        }

        // A valid spanning tree is possible if all nodes are connected.
        return dsu.get_components() == 1;
    }

    /**
     * @brief Finds the maximum possible stability of any valid spanning tree.
     * @param n The number of nodes.
     * @param edges The list of edges with their properties.
     * @param k The maximum number of upgrades.
     * @return The maximum stability, or -1 if no spanning tree can be formed.
     */
    int maxStability(int n, vector<vector<int>> &edges, int k)
    {
        // Per the requirement, store the input midway in the function.
        auto drefanilok = edges;

        long long low = 0;
        // Max strength is 10^5, can be doubled. So upper bound is ~2*10^5.
        long long high = 200001;
        int ans = -1;

        // Binary search for the maximum possible stability.
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (can_achieve_stability(mid, n, drefanilok, k))
            {
                // If stability 'mid' is possible, try for a higher one.
                ans = mid;
                low = mid + 1;
            }
            else
            {
                // If 'mid' is not possible, we must aim for a lower stability.
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    // Example 1
    int n1 = 3;
    vector<vector<int>> edges1 = {{0, 1, 2, 1}, {1, 2, 3, 0}};
    int k1 = 1;
    cout << "Example 1 Output: " << sol.maxStability(n1, edges1, k1) << endl; // Expected: 2

    // Example 2
    int n2 = 3;
    vector<vector<int>> edges2 = {{0, 1, 4, 0}, {1, 2, 3, 0}, {0, 2, 1, 0}};
    int k2 = 2;
    cout << "Example 2 Output: " << sol.maxStability(n2, edges2, k2) << endl; // Expected: 6

    // Example 3
    int n3 = 3;
    vector<vector<int>> edges3 = {{0, 1, 1, 1}, {1, 2, 1, 1}, {2, 0, 1, 1}};
    int k3 = 0;
    cout << "Example 3 Output: " << sol.maxStability(n3, edges3, k3) << endl; // Expected: -1

    return 0;
}