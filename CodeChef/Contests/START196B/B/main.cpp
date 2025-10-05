#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (k == 0)
    {
        cout << sum << '\n';
        return;
    }

    sort(a.begin(), a.end());
    int x = a[0];
    int y = a[1];

    for (long long i = 0; i < k; ++i)
    {
        // Calculate the value to add using the two smallest elements (x and y).
        // The formula (x + y + 1) / 2 is a robust way to compute ceil((x+y)/2.0)
        // using integer division, which works for both even and odd sums.
        long long val = (x + y + 1) / 2;

        // --- Stability Check ---
        // If the new value is not strictly smaller than the current second-smallest
        // element 'y', the state has stabilized. The pair (x, y) will be chosen
        // for all future operations, always producing the same 'val'.
        if (val >= y)
        {
            // Calculate the sum for all remaining (k - i) operations at once.
            sum += (k - i) * val;
            break; // Exit the simulation.
        }

        // --- If Not Stable ---
        // Add the new value for this single operation.
        sum += val;
        // Update 'y' to the new, smaller value. 'x' remains the same.
        y = val;
    }

    cout << sum << '\n';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        // input
        solve();
    }

    return 0;
}
