#include <bits/stdc++.h>
using namespace std;



bool ispossible(int x, int aind, int bind){
    // aind: decrease 
}

void solve(int n, vector<int>& arr){
    // code
    for(int i=0; i<n; i++){
        // i, n-i+1
        if(!ispossible(arr[i],i+1,n-i)){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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
