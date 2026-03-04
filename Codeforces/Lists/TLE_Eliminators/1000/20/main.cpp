#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    // input here only
    int mexofarr,xorofarr;
    cin>>mexofarr>>xorofarr;

    int ans=mexofarr;

    int newx=0;
    for(int i=0; i<mexofarr; i++){
        newx=newx^i;
    }
    // newx ^ needed = xorofarr
    if(newx==xorofarr) {
        cout<< ans<<endl;
        return;
    }
    else if( newx !=0 ){
        ans+=1;
        cout<<ans<<endl;
        return;
    }
    else {
        cout<<ans+2<<endl;
        return;
    }
    // if(newx==xorofarr) {
    //     cout<< ans<<endl;
    //     return;
    // }
    // else if( newx !=0 ){
    //     ans+=1;
    //     cout<<ans<<endl;
    //     return;
    // }
    // else {
    //     cout<<ans+2<<endl;
    //     return;
    // }
}

// void solve(ll n, vector<ll>& a){

// }

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        // ll n;
        // cin>>n;
        // vector<ll> a(n);
        // for (int i = 0; i < n; i++)
        // {
        //     cin>>a[i];
        // }
        // solve(n,a);
        
        solve();
    }

    return 0;
}
