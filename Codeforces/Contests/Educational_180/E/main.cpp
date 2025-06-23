#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    long long total_count = 0;

    // Case 1: Count triplets where the largest chosen element is a[n-1].
    // We need to find pairs (i, j) with i < j < n-1 such that a[i] + a[j] > a[n-1].
    // We can use a two-pointer approach on the subarray a[0...n-2].
    if (n >= 3)
    {
        long long count1 = 0;
        int L = 0;
        int R = n - 2;
        while (L < R)
        {
            if (a[L] + a[R] > a[n - 1])
            {
                // If a[L] + a[R] works, then any element a[L'] where L < L' < R
                // will also work with a[R] because a[L'] >= a[L].
                // So, pairs (L, R), (L+1, R), ..., (R-1, R) are all valid.
                count1 += (long long)(R - L);
                R--;
            }
            else
            {
                // The sum is too small, need a larger value for a[L].
                L++;
            }
        }
        total_count += count1;
    }

    // Case 2: Count triplets where the largest chosen element's index r is less than n-1.
    long long count2 = 0;
    // Iterate through all possible largest elements a[r] where r < n-1.
    for (int r = n - 2; r >= 1; --r)
    {
        // For a fixed r, we need to count pairs (p, q) with p < q < r such that:
        // 1. a[p] + a[q] > a[r]
        // 2. a[p] + a[q] + a[r] > a[n-1] => a[p] + a[q] > a[n-1] - a[r]
        // This combines to a[p] + a[q] > max(a[r], a[n-1] - a[r]).
        long long threshold = max(a[r], a[n - 1] - a[r]);

        // Now, count pairs (p, q) in a[0...r-1] where a[p] + a[q] > threshold.
        // This is the same two-pointer problem.
        int L = 0;
        int R = r - 1;
        while (L < R)
        {
            if (a[L] + a[R] > threshold)
            {
                count2 += (long long)(R - L);
                R--;
            }
            else
            {
                L++;
            }
        }
    }
    total_count += count2;

    cout << total_count << endl;
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
