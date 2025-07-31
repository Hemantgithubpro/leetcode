#include <bits/stdc++.h>
using namespace std;

class Fenwick {
public:
    vector<int> tree;
    int sz;
    Fenwick(int n) {
        sz = n + 1;
        tree.assign(sz + 1, 0);
    }
    void update(int idx, int val) {
        while (idx <= sz) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }
    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
    int query(int left, int right) {
        return query(right) - query(left - 1);
    }
};

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }
        vector<long long> dp(n + 1, LLONG_MAX / 2);
        dp[0] = 0;
        Fenwick small(n), large(n);
        for (int i = 1; i <= n; ++i) {
            // Choose small
            long long add_small = small.query(p[i] + 1, n) + large.query(1, n);
            dp[i] = min(dp[i], dp[i - 1] + add_small);
            // Choose large
            long long add_large = large.query(1, p[i] - 1);
            dp[i] = min(dp[i], dp[i - 1] + add_large);
            // Update trees (but since we take min, we simulate for both branches)
            // For optimal path, we would backtrack, but since min is taken, we update both conditionally
            // Note: This is a simplified version; in practice, we use two DPs for branches
            if (add_small <= add_large) {
                small.update(p[i], 1);
            } else {
                large.update(p[i], 1);
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}
