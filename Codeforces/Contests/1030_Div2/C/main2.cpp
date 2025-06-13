#include <bits/stdc++.h>
#define ll long long
using namespace std;

// count the no. of set bits
int bea(int a){
    int ans = 0;
    while(a){
        if(a & 1) ans++;
        a >>= 1;
    }
    return ans;
}

void solve(){
    // input here only
    ll n; cin>>n;
    ll k; cin>>k;
    vector<int> a(n);
    // unordered_map<int,int> um;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        // um[a[i]]++;
    }

    sort(a.begin(),a.end());
    for (int i = 0; i < n; i++)
    {
        ll temp=k;
        while(temp--){
            if(bea(a[i]+1)>bea(a[i])){
                k--;
                a[i]+=1;
            }
            // i'm thinking about local maxima vs universal maxima here.
        }
    }

    int ans=0;
    for (int i = 0; i < n; i++)
    {
        ans+=bea(a[i]);
    }
    cout<<ans<<endl;
    
    // if k is too large, that is the problem.

    
    
    
    
    
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
