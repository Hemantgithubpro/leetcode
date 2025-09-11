#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long initial_alt_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if ((i + 1) % 2 != 0) { // 1-based odd position
            initial_alt_sum += a[i];
        } else { // 1-based even position
            initial_alt_sum -= a[i];
        }
    }

    // Option 1: Alice stops immediately.
    long long max_val = initial_alt_sum;

    // --- Option 2: Alice makes one optimal swap ---

    // Case A: Swap elements at same-parity indices. Gain = r-l.
    if (n > 1) {
        long long max_dist_same_parity = (n % 2 != 0) ? (long long)n - 1 : (long long)n - 2;
        max_val = max(max_val, initial_alt_sum + max_dist_same_parity);
    }
    
    // Case B: Swap elements at different-parity indices.

    // B1: l is odd, r is even (l < r). Maximize gain = (r+2a_r) - (l+2a_l).
    if (n > 1) {
        vector<long long> f(n);
        for(int i = 0; i < n; ++i) f[i] = (long long)(i + 1) + 2 * a[i];

        vector<long long> f_odd_prefix_min(n, LLONG_MAX);
        long long current_min = LLONG_MAX;
        for(int i = 0; i < n; ++i) {
            if((i + 1) % 2 != 0) current_min = min(current_min, f[i]);
            f_odd_prefix_min[i] = current_min;
        }

        for(int r = 0; r < n; ++r) {
            if((r + 1) % 2 == 0 && r > 0) {
                long long min_f_l = f_odd_prefix_min[r - 1];
                if (min_f_l != LLONG_MAX) {
                    max_val = max(max_val, initial_alt_sum + f[r] - min_f_l);
                }
            }
        }
    }

    // B2: l is even, r is odd (l < r). Maximize gain = (2a_l-l) - (2a_r-r).
    if (n > 1) {
        vector<long long> g(n);
        for(int i = 0; i < n; ++i) g[i] = 2 * a[i] - (long long)(i + 1);

        vector<long long> g_odd_suffix_min(n, LLONG_MAX);
        long long min_val = LLONG_MAX;
        for(int i = n - 1; i >= 0; --i) {
            if((i + 1) % 2 != 0) min_val = min(min_val, g[i]);
            g_odd_suffix_min[i] = min_val;
        }

        vector<long long> g_even_prefix_max(n, LLONG_MIN);
        long long max_val_g = LLONG_MIN;
        for(int i = 0; i < n; ++i) {
            if((i + 1) % 2 == 0) max_val_g = max(max_val_g, g[i]);
            g_even_prefix_max[i] = max_val_g;
        }

        // Iterate over all possible split points between l and r
        for(int i = 0; i < n - 1; ++i) {
            long long max_g_l = g_even_prefix_max[i];
            long long min_g_r = g_odd_suffix_min[i + 1];
            if(max_g_l != LLONG_MIN && min_g_r != LLONG_MAX) {
                max_val = max(max_val, initial_alt_sum + max_g_l - min_g_r);
            }
        }
    }

    cout << max_val << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}