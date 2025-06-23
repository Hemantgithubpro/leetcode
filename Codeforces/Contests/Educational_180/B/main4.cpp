#include <bits/stdc++.h>
using namespace std;

// Function to check if two integer ranges [min1, max1] and [min2, max2]
// can produce numbers x and y such that |x - y| <= 1.
bool are_ranges_close(long long min1, long long max1, long long min2, long long max2)
{
    return max1 >= min2 - 1 && max2 >= min1 - 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    if (n == 0)
    {
        cout << -1 << endl;
        return;
    }
    if (n == 1)
    {
        cout << -1 << endl;
        return;
    }

    // Case 0: 0 operations
    // Check if the array is already beautiful.
    for (int i = 0; i < n - 1; ++i)
    {
        if (abs(a[i] - a[i + 1]) <= 1)
        {
            cout << 0 << endl;
            return;
        }
    }

    long long min_ops = -1;

    // Helper to update min_ops
    auto update_min_ops = [&](long long ops)
    {
        if (ops >= 0)
        {
            if (min_ops == -1 || ops < min_ops)
            {
                min_ops = ops;
            }
        }
    };

    // Case 1: Merge one contiguous block a[i...j] and pair it with an adjacent original element.
    // Time complexity: O(N^2)
    for (int i = 0; i < n; ++i)
    {
        long long current_min = a[i];
        long long current_max = a[i];
        for (int j = i; j < n; ++j)
        {
            current_min = min(current_min, a[j]);
            current_max = max(current_max, a[j]);
            long long ops = j - i;
            if (n - ops < 2)
                continue; // Final array must have at least 2 elements.

            if (i > 0)
            {
                if (are_ranges_close(current_min, current_max, a[i - 1], a[i - 1]))
                {
                    update_min_ops(ops);
                }
            }
            if (j < n - 1)
            {
                if (are_ranges_close(current_min, current_max, a[j + 1], a[j + 1]))
                {
                    update_min_ops(ops);
                }
            }
        }
    }

    // Case 2: Merge two adjacent blocks a[i...k] and a[k+1...j].
    // Time complexity: O(N^2) using two pointers.
    for (int k = 0; k < n - 1; ++k)
    {
        // Precompute ranges for the right block a[k+1 ... j]
        vector<long long> r_mins(n), r_maxs(n);
        r_mins[k + 1] = a[k + 1];
        r_maxs[k + 1] = a[k + 1];
        for (int j = k + 2; j < n; ++j)
        {
            r_mins[j] = min(r_mins[j - 1], a[j]);
            r_maxs[j] = max(r_maxs[j - 1], a[j]);
        }

        long long l_min = a[k];
        long long l_max = a[k];
        int j_ptr = n - 1;

        for (int i = k; i >= 0; --i)
        {
            l_min = min(l_min, a[i]);
            l_max = max(l_max, a[i]);

            // As i decreases, l_min decreases and l_max increases, so the condition
            // for being close becomes easier to satisfy. This means the optimal j
            // for the current i will be <= the optimal j for i+1.
            // So we can use a two-pointer approach for j.
            while (j_ptr > k + 1 && are_ranges_close(l_min, l_max, r_mins[j_ptr - 1], r_maxs[j_ptr - 1]))
            {
                j_ptr--;
            }

            if (are_ranges_close(l_min, l_max, r_mins[j_ptr], r_maxs[j_ptr]))
            {
                long long ops = (k - i) + (j_ptr - (k + 1));
                if (n - ops >= 2)
                {
                    update_min_ops(ops);
                }
            }
        }
    }

    cout << min_ops << endl;
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
