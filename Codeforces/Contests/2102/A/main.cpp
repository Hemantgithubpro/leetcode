#include <bits/stdc++.h>
using namespace std;

bool isok(vector<int> &a, int m, int p, int q){
    int sum=0;
    for(int i=0; i<a.size(); i++){
        sum+=a[i];
    }
    if(sum!=m) return false;
    int sum1=0;
    for(int i=0; i<p; i++){
        sum1+=a[i];
    }
    if(sum1!=q) return false;
    int l=0;
    int r=p;
    while(r<a.size()){
        sum1+=a[r];
        sum1-=a[l];
        l++;
        r++;
        if(sum1!=q) return false;
    }
    return true;
}

// this soln is brute force
void solve(int n, int m, int p, int q){
    vector<int> arr(n,0);
    
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
        int n;
        cin>>n;
        int m;
        cin>>m;
        int p;
        cin>>p;
        int q;
        cin>>q;
        solve(n,m,p,q);
    }

    return 0;
}
