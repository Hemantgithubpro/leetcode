#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> s(n + 1);
    // Use a set to store unvisited dominoes, sorted by size.
    // The pair is {size, index}.
    set<pair<long long, int>> unvisited;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i];
        unvisited.insert({s[i], i});
    }

    // BFS queue: stores {domino_index, path_length}
    queue<pair<int, int>> q;

    // Initial state for BFS: Start with domino 1.
    // Check if domino 1 exists before processing.
    if (unvisited.count({s[1], 1}))
    {
        q.push({1, 1});
        unvisited.erase({s[1], 1});
    }
    else
    {
        // This case should not happen based on problem description but is a safe check.
        cout << -1 << "\n";
        return;
    }

    // BFS main loop
    while (!q.empty())
    {
        pair<int, int> current_pair = q.front();
        int u = current_pair.first;
        int d = current_pair.second;
        q.pop();

        // If we reached the destination domino N, we are done.
        // BFS guarantees the first time we reach a node, it's via a shortest path.
        if (u == n)
        {
            cout << d << "\n";
            return;
        }

        // The condition for domino u to topple domino v is S_v <= 2 * S_u.
        long long max_s_reachable = 2LL * s[u];

        // Efficiently find and process all newly reachable dominoes.
        // We iterate through the unvisited set from the smallest size.
        set<pair<long long, int>>::iterator it = unvisited.begin();
        while (it != unvisited.end() && it->first <= max_s_reachable)
        {
            int v = it->second;
            q.push({v, d + 1});

            // Erase the visited domino and get an iterator to the next one.
            it = unvisited.erase(it);
        }
    }

    // If the queue becomes empty and we haven't reached domino N, it's impossible.
    cout << -1 << "\n";
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
        // input
        solve();
    }

    return 0;
}
