#include <bits/stdc++.h>
using namespace std;

void solve(){
    // code
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
    string s="";
    while (t--) {
        char a; cin>>a;
        int n; cin>>n;
        while(n--) s+=a;
        if(s.size()>100){
            cout<<"Too Long"<<endl;
            return 0;
        }
    }
    cout<<s;

    return 0;
}
