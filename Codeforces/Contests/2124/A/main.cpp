#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool isder(vector<int>&a , vector<int>&b){
    // b is sorted
    for(int i=0; i<a.size(); i++){
        if(a[i]==b[i]) return false;
    }
    return true;
}

void print(vector<int> &b){
    cout<<"YES"<<endl;
    cout<<b.size()<<endl;
    for (int i = 0; i < b.size(); i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
}

void solve(){
    // input here only
    int n; cin>>n; 
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    vector<int> b=a;
    sort(b.begin(),b.end());
    if(isder(a,b)){
        print(b);
        return;
    }

    if(n%2==0){
        vector<int> b=a;
        sort(b.begin(),b.end(),greater<int>());
        if(isder(a,b)){
            print(b);
            return;
        }
        else{   // start deleting duplicates
            vector<int> c;
            int i,j=0;
            
            
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
