#include <bits/stdc++.h>
using namespace std;

bool isBeautiful(const vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (abs(arr[i] - arr[i + 1]) <= 1)
        {
            return true;
        }
    }
    return false;
}

int solve(vector<int> &a)
{
    int n = a.size();

    // Check if already beautiful
    if (isBeautiful(a))
    {
        return 0;
    }

    // If size is 2 and not beautiful, impossible
    if (n == 2)
    {
        return -1;
    }

    int minOps = INT_MAX;

    // Try all possible single merge operations
    for (int i = 0; i < n - 1; i++)
    {
        // Try different values in the range [min(a[i], a[i+1]), max(a[i], a[i+1])]
        int minVal = min(a[i], a[i + 1]);
        int maxVal = max(a[i], a[i + 1]);

        // Try a few strategic values
        vector<int> candidates = {minVal, maxVal, (minVal + maxVal) / 2};

        for (int newVal : candidates)
        {
            if (newVal >= minVal && newVal <= maxVal)
            {
                vector<int> temp = a;
                temp.erase(temp.begin() + i + 1);
                temp[i] = newVal;

                if (isBeautiful(temp))
                {
                    minOps = min(minOps, 1);
                }
            }
        }
    }

    // If single operation works, return it
    if (minOps == 1)
    {
        return 1;
    }

    // Try BFS approach for minimum operations
    queue<pair<vector<int>, int>> q;
    set<vector<int>> visited;

    q.push({a, 0});
    visited.insert(a);

    while (!q.empty())
    {
        vector<int> curr = q.front().first;
        int ops = q.front().second;
        q.pop();

        if (ops >= 3)
            break; // Limit search depth

        // Try all possible merge operations
        for (int i = 0; i < curr.size() - 1; i++)
        {
            int minVal = min(curr[i], curr[i + 1]);
            int maxVal = max(curr[i], curr[i + 1]);

            // Try key values in the range
            for (int newVal = minVal; newVal <= maxVal; newVal++)
            {
                vector<int> next = curr;
                next.erase(next.begin() + i + 1);
                next[i] = newVal;

                if (isBeautiful(next))
                {
                    minOps = min(minOps, ops + 1);
                }

                if (visited.find(next) == visited.end() && ops + 1 < 3)
                {
                    visited.insert(next);
                    q.push({next, ops + 1});
                }
            }
        }
    }

    return (minOps == INT_MAX) ? -1 : minOps;
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
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout << solve(a) << "\n";
    }

    return 0;
}