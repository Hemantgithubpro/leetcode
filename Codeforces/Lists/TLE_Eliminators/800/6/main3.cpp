#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& a){
    // code
    if(n==2){
        cout<<"yes"<<endl;
        return;
    }
    sort(a.begin(),a.end());
    long long k=a[0]+a[n-1];
    for(int i=0; i<n; i++){
        if(i%2==0){
            if(a[i]+a[n-i-1] !=k){
                cout<<"no"<<endl;
                return;
            }
        }
        else{
            if(a[i]+a[n-i]!=k){
                cout<<"no"<<endl;
                return;
            }
        }
    }
    cout<<"yes"<<endl;
    
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
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        solve(n, a);
    }

    return 0;
}
