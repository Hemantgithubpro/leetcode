#include <bits/stdc++.h>
using namespace std;

int main() {
    // Test case 2: n=2, k=1, timestamps=[4,5,6,9]
    vector<long long> a = {4, 5, 6, 9};
    int n = 2, k = 1;
    
    cout << "All possible intervals:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            cout << "(" << a[i] << "," << a[j] << ") = " << a[j] - a[i] << endl;
        }
    }
    
    cout << "\nFor k=1, checking different combinations:" << endl;
    
    // Single interval options
    cout << "Single intervals:" << endl;
    cout << "(4,5) = 1" << endl;
    cout << "(4,6) = 2" << endl; 
    cout << "(4,9) = 5" << endl;
    cout << "(5,6) = 1" << endl;
    cout << "(5,9) = 4" << endl;
    cout << "(6,9) = 3" << endl;
    
    // Two non-overlapping intervals
    cout << "\nTwo non-overlapping intervals:" << endl;
    cout << "(4,5) + (6,9) = 1 + 3 = 4" << endl;
    cout << "(5,6) + others: not possible due to timestamp overlap" << endl;
    
    cout << "\nSo maximum for k=1 should be max(5 from single interval, 4 from two intervals)" << endl;
    cout << "But expected output is 4, suggesting we prefer multiple visitors over single long stay" << endl;
    
    return 0;
}