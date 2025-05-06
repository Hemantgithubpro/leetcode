#include <bits/stdc++.h>
using namespace std;

void solve(int &n, int &k, string &s, vector<int> &a) {
    vector<int> unknownindices;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0'){
            unknownindices.push_back(i);
        }
    }
    if(unknownindices.size() == 0){
        int sum=0;
        for(int i=0; i<n; i++){
            sum += a[i];
        }
        if(sum==k){
            cout<<"Yes"<<endl;
            for(int i=0; i<n; i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        return;
    }

    if(unknownindices.size() == 1){
        int sum=0;
        for(int i=0; i<n; i++){
            sum += a[i];
        }
        if(sum<=k){
            a[unknownindices[0]] = k-sum;
            cout<<"Yes"<<endl;
            for(int i=0; i<n; i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        return;
    }

    if(unknownindices.size()>1){
        int m=unknownindices.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum += a[i];
        }
        if(sum>k){
            cout<<"No"<<endl;
            return;
        }
        int rest=k-sum;
        int x=rest/m;
        // int y=k%m;
        for(int i=0; i<m; i++){
            a[unknownindices[i]] = x;
            rest -= x;
        }
        if(rest>0){
            for(int i=0; i<m; i++){
                if(rest>0){
                    a[unknownindices[i]]++;
                    rest--;
                }
            }
        }
        cout<<"Yes"<<endl;
        for(int i=0; i<n; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        // for(int i=0; i<y; i++){
        //     a[unknownindices[i]]++;
        // }
    }

    // int m = unknownindices.size();
    // vector<int> dp(m+1,0);
    // dp[0] = 0;
    // for(int i=1; i<=m; i++){
    //     dp[i] = dp[i-1] + a[unknownindices[i-1]];
    // }
    // int ans = INT_MAX;
    // for(int i=0; i<=m; i++){
    //     int l = dp[i];
    //     int r = dp[m] - dp[i];
    //     if(abs(l-r) <= k){
    //         ans = min(ans, abs(l-r));
    //     }
    // }
    // if(ans == INT_MAX){
    //     cout << -1 << endl;
    // } else {
    //     cout << ans << endl;
    // }
    
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
        int k;
        cin>>k;
        string s;
        cin>>s;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(n,k,s,a);
    }

    return 0;
}
