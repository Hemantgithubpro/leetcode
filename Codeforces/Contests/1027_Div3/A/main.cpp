#include <bits/stdc++.h>
using namespace std;

void solve(string s){
    int a=0,b=0;
    long long x=stoi(s);
    double y=pow(x,0.5);
    if(y-floor(y) !=0 || x<0) cout<<-1<<endl;
    else{
        a=y/2;
        b=y-a;
        if(a!=b) cout<<a<<" "<<b<<endl;
        else{
            a+=1;
            b-=1;
            if(b>=0 && a>=0) cout<<a<<" "<<b<<endl;
            else cout<<-1<<endl;
        }
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
        string s;
        cin>>s;
        solve(s);
    }

    return 0;
}
