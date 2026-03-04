#include <bits/stdc++.h>
#define ll long long

using namespace std;

static long long xor_upto(long long n) {
    // XOR of all integers in [0, n]
    if (n < 0) return 0;
    switch (n & 3LL) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        default: return 0;
    }
}

void solve(){
    // input here only
    long long mexofarr, xorofarr;
    cin>>mexofarr>>xorofarr;

    long long ans = mexofarr;

    // XOR of [0, mexofarr-1]
    long long prefix = xor_upto(mexofarr - 1);

    if (prefix == xorofarr) {
        cout << ans << '\n';
        return;
    }

    long long needed = prefix ^ xorofarr;
    // If we add 'needed' and it equals mexofarr, mex would increase, so we need two numbers.
    if (needed == mexofarr) {
        cout << ans + 2 << '\n';
    } else {
        cout << ans + 1 << '\n';
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
