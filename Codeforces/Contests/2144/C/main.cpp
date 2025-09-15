#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<bool> present(n + 1, false);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (p[i] > 0) {
            present[p[i]] = true;
        }
    }

    // 1. Find the length of the *forced* sorted prefix.
    // L_prefix_fixed will be the 1-based index of the last element of this prefix.
    int L_prefix_fixed = 0;
    for (int i = 0; i < n; ++i) {
        // We use 1-based indexing for the value comparison (i+1)
        if (p[i] > 0 && p[i] == (i + 1)) {
            L_prefix_fixed = i + 1;
        } else {
            // First time we see a 0 or a fixed mismatch
            break;
        }
    }

    // 2. Find the length of the *forced* sorted suffix.
    int R_suffix_fixed_len = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (p[i] > 0 && p[i] == (i + 1)) {
            R_suffix_fixed_len++;
        } else {
            // First time from the right we see a 0 or a fixed mismatch
            break;
        }
    }

    // 3. Define the "active" segment [L, R] using 1-based indexing
    int L = L_prefix_fixed + 1;
    int R = n - R_suffix_fixed_len;

    // 4. If L > R, the fixed parts overlap/meet, forcing a sorted array.
    if (L > R) {
        cout << 0 << endl;
        return;
    }

    // 5. Analyze the segment [L, R]
    bool fixed_mismatch_in_seg = false;
    set<int> Z_seg; // Set of zero indices (1-based)
    set<int> M_seg; // Set of missing numbers that "belong" in this range (1-based)

    for (int i = L; i <= R; ++i) {
        // p is 0-indexed, so we check p[i-1] for index i
        if (p[i - 1] > 0) {
            // By definition of L and R, any fixed p[i-1] *must* be != i.
            fixed_mismatch_in_seg = true;
        } else {
            Z_seg.insert(i); // i is a zero index
        }

        if (!present[i]) {
            M_seg.insert(i); // i is a missing number
        }
    }

    // 6. Check for the only case where cost is 0:
    //    - No fixed mismatches in the segment.
    //    - The zeros *must* be filled by their corresponding indices (Z_seg == M_seg).
    //    - There is at most 1 such zero (if > 1, we can swap them to create a mismatch).
    if (!fixed_mismatch_in_seg && (Z_seg == M_seg) && Z_seg.size() <= 1) {
        cout << 0 << endl;
    } else {
        // In all other cases, we *either* have a fixed mismatch,
        // or we *cannot* sort the zeros (Z_seg != M_seg),
        // or we *can choose* to not sort the zeros (Z_seg == M_seg, |Z_seg| > 1).
        // This means the max cost is the full length of the active segment.
        cout << (R - L + 1) << endl;
    }
}

// void solve(ll n, vector<ll>& a){

// }

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
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
