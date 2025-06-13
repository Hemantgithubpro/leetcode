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
    int n; cin>>n;
    int k; cin>>k;
    vector<int> a(n);
    unordered_map<int,int> um;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        um[a[i]]++;
    }

    // i've to find numbers in array with 2^(n)-2 value, then +1 will make it 2^(n)-1
    // vector<ll> powerof2;
    unordered_set<ll> powerof2;
    for (ll i = 0; i < 100; i++)
    {
        powerof2.insert(pow(2,i));
    }
    for (int i = 0; i < n; i++)
    {
        if(powerof2.find(a[i]+2)!=powerof2.end()){
            k--;
            
        } 
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
