#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        
        if (k == 0) {
            cout << "YES" << endl;
            continue;
        }
        
        if (k == 1) {
            bool has_one = false;
            for (char c : s) {
                if (c == '1') {
                    has_one = true;
                    break;
                }
            }
            if (has_one) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
                for (int i = 1; i <= n; i++) {
                    cout << i << " ";
                }
                cout << endl;
            }
            continue;
        }
        
        int max_run = 0;
        int current = 0;
        for (char c : s) {
            if (c == '1') {
                current++;
                max_run = max(max_run, current);
            } else {
                current = 0;
            }
        }
        
        if (max_run >= k) {
            cout << "NO" << endl;
            continue;
        }
        
        int count0 = 0;
        for (char c : s) {
            if (c == '0') count0++;
        }
        int count1 = n - count0;
        
        vector<int> ans(n);
        int large_start = n - count0 + 1;
        int small_start = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                ans[i] = large_start++;
            } else {
                ans[i] = small_start++;
            }
        }
        
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}