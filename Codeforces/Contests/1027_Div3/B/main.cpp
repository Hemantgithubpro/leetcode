#include <bits/stdc++.h>
using namespace std;

int countgoodpairs(int n,string &s){
    // n is even
    // 010001
    n--;
    // n=5, n/2=2
    int a=0;
    for(int i=0; i<n/2; i++){
        if(s[i]==s[n-i]) a++;
    }
    return a;
}

int noof1(string &s){
    int n1=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='1') n1++;
    }
    return n1;
}

int noof0(string &s){
    int n0=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0') n0++;
    }
    return n0;
}

void solve(int n, int k, string& s){
    int a=countgoodpairs(n,s);
    int n1=noof1(s);
    int n0=noof0(s);
    if(a==k) cout<<"YES"<<endl;
    else if(a>k){
        // to reduce good pairs
        if(n1>n0){
            if((n1-n0)/2 <=k ) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else if(n1<n0){
            if((n0-n1)/2 <=k ) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    else{
        // to increase good pairs
        if(n1>n0){
            if((n1-n0)<k ) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else if(n1<n0){
            if((n0-n1)<k ) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
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
        // input
        int n;
        cin>>n;
        int k;
        cin>>k;
        string s;
        cin>>s;
        solve(n,k,s);
    }

    return 0;
}
