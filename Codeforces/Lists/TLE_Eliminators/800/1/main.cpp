#include <bits/stdc++.h>
using namespace std;

// [Halloumi Boxes](https://codeforces.com/problemset/problem/1903/A)

bool ifalreadysorted(vector<int>& a){
    for (int i = 1; i < a.size(); i++)
    {
        if(a[i]<a[i-1]) return false;
    }
    return true;
}

void solve(int n, int k, vector<int>& a){
    if(ifalreadysorted(a)){
        cout<<"YES"<<endl;
        return;
    }
    else if(k>1){
        cout<<"YES"<<endl;
        return;
    }
    else if(k==1 && !ifalreadysorted(a)){
        cout<<"NO"<<endl;
        return;
    }   
    else cout<<"NO"<<endl;
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
        int k;
        cin>>k;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        solve(n,k,a);
    }

    return 0;
}
