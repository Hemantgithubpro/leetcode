#include <bits/stdc++.h>
using namespace std;
// incomplete
bool isallzero(string& a){
    for(int i=0; i<a.length(); i++){
        if(a[i]!='0') return false;
    }
    return true;
}

void solve(int n, string& a, string &b){
    // if(a[0]=='1'){
    //     cout<<"NO"<<endl;
    //     return;
    // }
    // // int l=0,r=0;
    // for(int i=2; i<n; i++){
    //     if(a[i]=='1'){
    //         if(b[i-1]=='0') swap(a[i],b[i-1]);
    //     }
        
    //     if(b[i]=='1' && a[i-1]=='0') swap
    // }

    // find alternate positions where '1' occurs
    vector<int> pos;
    for(int i=0; i<a.length(); i++){
        if(a[i]=='1') pos.push_back(i);
    }
    // a="010001"
    // pos={1,5}
    // b="010111"
    // for i in pos, check b[i-1]
    // if(b[i-1]=='0') swap
    // else check a[i-2] recursively.
    for(int i=0; i<pos.size(); i++){
        if(b[pos[i]-1]=='0') swap(a[pos[i]],b[pos[i]-1]);
        else{

        }
    }






    if(isallzero(a))cout<<"YES"<<endl;
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
        string a;
        cin>>a;
        string b;
        cin>>b;
        solve(n,a,b);
    }

    return 0;
}
