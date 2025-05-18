#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& arr){
    // no. of win = no. of loss, no(0)=no(1), no(0)<no(1)
    int sum=arr[0];
    for(int i=0; i<n-1; i++){
        if(arr[i]+arr[i+1] <1){
            cout<<"YES"<<endl;
            return;
        }
        sum+=arr[i+1];
    }
    if(sum==n){
        cout<<"YES"<<endl;
        return;
    }
    else{
        cout<<"NO"<<endl;
        return;
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
