#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long long> a = {6149048, 26582657, 36124499, 43993239, 813829899, 860114890, 910238130, 913669539};
    int n = 4;
    
    cout << "Timestamps: ";
    for (auto x : a) cout << x << " ";
    cout << endl;
    
    cout << "\nExpected output: 78018749 173782233 184532695 338503015" << endl;
    cout << "My output:       840393509 1737022233 2477482524 3385003015" << endl;
    
    cout << "\nLet me analyze what intervals give the expected k=1 result (78018749):" << endl;
    
    // For k=1, try to find combination that gives 78018749
    vector<pair<long long, pair<int,int>>> intervals;
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            intervals.push_back({a[j] - a[i], {i, j}});
        }
    }
    
    sort(intervals.begin(), intervals.end(), greater<>());
    
    cout << "Top intervals by stay time:" << endl;
    for (int i = 0; i < min(10, (int)intervals.size()); i++) {
        auto [stay, indices] = intervals[i];
        auto [start_idx, end_idx] = indices;
        cout << "(" << a[start_idx] << "," << a[end_idx] << ") = " << stay << endl;
    }
    
    // Check what combination could give 78018749
    cout << "\nLooking for combinations that sum to 78018749..." << endl;
    
    return 0;
}