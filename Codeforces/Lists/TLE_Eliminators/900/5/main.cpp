#include <bits/stdc++.h>
using namespace std;

vector<int> operation(vector<int>&arr, int l, int r){
    long long s=arr[l];
    for (int i = l+1; i <= r; i++)
    {
        s=s^arr[i];
    }

    for (int i = l; i <= r; i++)
    {
        arr[i]=s;
    }
    return arr;
}



void solve(){
    // change all elements in array to 0
    // operations: at most 8 times
    int n; cin>>n;
    int a[n]; 
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
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
        solve();
    }

    return 0;
}
