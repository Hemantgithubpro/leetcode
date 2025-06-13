#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    // input here only
    int n; cin>>n;
    int k; cin>>k;
    string ans;

    int noof1=k;
    int noof0=n-k;
    if(noof1==noof0){
        while(n--){
            if(n%2) ans+='1';
            else ans+='0';
        }
        cout<<ans<<endl;
    }
    else if(noof1==0){
        while(n--) ans+='0';
        cout<<ans<<endl;
    }
    else if(noof0==0){
        while(n--) ans+='1';
        cout<<ans<<endl;
    }
    else if(noof0>noof1){
        int i=1;
        while(noof0>1 && noof0>0){
            if(i%2) {
                ans+='1';
                noof1--;
            }
            else {
                ans+='0';
                noof0--;
            }
            i++;
        }
        ans+='1';
        ans+='0';
        // while(noof0) ans+='0';
        cout<<ans<<endl;
    }
    else if(noof1>noof0){
        int i=1;
        while(noof0>1 && noof1>0){
            if(i%2) ans+='1';
            else {
                ans+='0';
                noof0--;
            }
            i++;
        }
        while(noof1) ans+='1';
        ans+='0';
        cout<<ans<<endl;
    }
    
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
