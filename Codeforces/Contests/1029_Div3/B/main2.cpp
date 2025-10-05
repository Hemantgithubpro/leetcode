#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> result(n);
        
        if (n % 2 == 1) {
            int left = 0, right = n - 1;
            
            for (int i = 1; i <= n; i++) {
                if (i % 2 == 1) {
                    result[left++] = i;
                } else {
                    result[right--] = i;
                }
            }
        } else {
            int pos = 0;
            
            for (int i = 2; i <= n; i += 2) {
                result[pos++] = i;
            }
            for (int i = n - 1; i >= 1; i -= 2) {
                result[pos++] = i;
            }
        }
        
        for (int i = 0; i < n; i++) {
            cout << result[i];
            if (i < n - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}