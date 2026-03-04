#include <bits/stdc++.h>
#define ll long long

using namespace std;

double loga(double val,double base){
    return log(val)/log(base);
}

// void solve(){
//     // input here only
//     int a,b; cin>>a>>b;

//     int ans=0;
//     if(b==1){
//         b++;
//         ans++;
//     }

//     for(int i=b; i<a; i++){
        
//     }
// }

// void solve(ll n, vector<ll>& a){

// }

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     while (t--) {
//         // ll n;
//         // cin>>n;
//         // vector<ll> a(n);
//         // for (int i = 0; i < n; i++)
//         // {
//         //     cin>>a[i];
//         // }
//         // solve(n,a);
        
//         solve();
//     }


    int a=1337;
    int b=1;
    double ans=0;
    if(b==1){
        b++;
        ans++;
    }
    b++;ans++;
    b++;ans++;
    b++; ans++;
    // b++; ans++;
    ans+=loga(a,b);
    cout<<ans<<endl;
    return 0;
}
