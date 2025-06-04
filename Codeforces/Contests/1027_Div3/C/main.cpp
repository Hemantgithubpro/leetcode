#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& arr){
    int ans=1;
    for(int i=1; i<n; i++){
        int temp=arr[i-1];
        if(temp+1 < arr[i]){
            // dont remove it
            ans++;
        }
        else{
            // remove it
            if(i+1 < n){
                if(temp==arr[i]);
                else if(arr[i]!=arr[i+1]){
                    ans++;
                }
                i++;
            }
        }
    }
    cout<<ans<<endl;
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
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        solve(n, arr);
    }

    return 0;
}
