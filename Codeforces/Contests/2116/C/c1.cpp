#include <bits/stdc++.h>
using namespace std;

// #define __gcd(a,b) gcd;

bool isonepresent(vector<int>& a){
    for(int i=0; i<a.size(); i++){
        if(a[i]==1) return true;
    }
    return false;
}

void solve(int n, vector<int>& arr){
    // from 1 to n, select i,j and i!=j 
    // to make all elements equal
    int ans=0;
    if(isonepresent(arr)){
        for(int i=0; i<n; i++){
            if(arr[i]!=1) ans++;
        }
        cout<<ans;
        return;
    }
    else{
        
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
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        solve(n,arr);
    }

    return 0;
}
