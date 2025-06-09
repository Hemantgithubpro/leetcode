// brute force, n^2
#include <bits/stdc++.h>
using namespace std;

bool iscool(vector<int>&arr, vector<int>& ind){
    for(int i=0; i<ind.size(); i++){
        for(int j=0; j<ind[i]; j++){
            
        }
    }
}

void solve(int n, vector<int>& arr){
    // code
    int ans=1;
    // unordered_set<int> us;
    unordered_map<int,int> um;
    unordered_map<int,int> um2;
    // unordered_map<int,bool> um;

    for(int i=0; i<n; i++){
        um[arr[i]]++;
    }

    

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    int t;
    cin >> t;
    while (t--) {
        // input
        int n;
        cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        solve(n,a);
    }

    return 0;
}
