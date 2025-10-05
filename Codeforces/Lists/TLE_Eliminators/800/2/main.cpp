#include <bits/stdc++.h>
using namespace std;

void solve(int n, int x, vector<int>& a){
    // code
    int p=(x-a[a.size()-1])*2;
    int q=p;
    for(int i=1; i<n; i++){
        q=max(q,a[i]-a[i-1]);
    }
    q=max(q,a[0]);
    cout<<q<<endl;
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
        int x;
        cin>>x;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        solve(n,x,a);
    }

    return 0;
}
