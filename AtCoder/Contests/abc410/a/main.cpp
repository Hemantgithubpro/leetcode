#include <bits/stdc++.h>
using namespace std;

void solve(){
    // code
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    // int t;
    // cin >> t;
    // while (t--) {
    //     // input
    //     solve();
    // }

    int n; cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]>=k) ans++;
    }
    cout<<ans;
    

    return 0;
}
