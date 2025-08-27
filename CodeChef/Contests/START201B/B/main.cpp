#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;cin>>n;
    string s; cin>>s;
    for(int i=1; i<n-1; i++){
        if(s[i]=='1'){
            s[i-1]='0';
            s[i]='0';
            s[i+1]='0';
        }
    }
    for(int i=0; i<n; i++)
        if(s[i]=='1'){
            cout<<"NO"<<endl;
            return;
        }
    cout<<"YES"<<endl;
}

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
        solve();
    }

    return 0;
}
