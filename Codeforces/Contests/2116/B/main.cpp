#include <bits/stdc++.h>
using namespace std;

// dp will be applied as we're calculating the value again and again.
void solve(int n, vector<int>& p, vector<int>& q){
    vector<int> ans(n);
    for(int i=0; i<n; i++){
        long long r=0,temp=0,temp2=0;
        for(int j=0; j<=i; j++){
            temp2=pow(2,p[j])+ pow(2,q[i-j]);
            temp = max(temp,temp2);
        }

        r=temp%998244353;
        ans[i]=r;
    }


    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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
        vector<int> p(n);
        for(int i=0; i<n; i++){
            cin>>p[i];
        }
        vector<int> q(n);
        for(int i=0; i<n; i++){
            cin>>q[i];
        }
        solve(n,p,q);
    }

    return 0;
}
