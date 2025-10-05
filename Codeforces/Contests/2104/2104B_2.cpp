#include <bits/stdc++.h>
using namespace std;

vector<long long> solve(vector<long long> &a, int n) {
    vector<long long> result(n);
    vector<long long> prefix_sum(2*n + 1, 0);
    
    // Create circular array by concatenating array with itself
    for(int i = 0; i < n; i++) {
        prefix_sum[i+1] = prefix_sum[i] + a[i];
        prefix_sum[i+n+1] = prefix_sum[i+n] + a[i];
    }
    
    // For each k, find maximum sum of k consecutive elements
    for(int k = 1; k <= n; k++) {
        long long maxSum = 0;
        // Check windows in both original and circular parts
        for(int i = 0; i <= n; i++) {
            maxSum = max(maxSum, prefix_sum[i+k] - prefix_sum[i]);
        }
        result[k-1] = maxSum;
    }
    return result;
}

int main() {
    int testcases;
    cin >> testcases;
    for(int i=0; i<testcases; i++) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int j=0; j<n; j++) {
            cin >> a[j];
        }
        vector<long long> result = solve(a,n);
        for(int j=0; j<result.size(); j++) {
            cout << result[j] << " ";
        }
        cout << endl;
    }
}