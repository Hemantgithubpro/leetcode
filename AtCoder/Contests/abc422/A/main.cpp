#include <bits/stdc++.h>
using namespace std;

void solve(){
    // code
    string s; 
    cin>>s;
    int i=s[0]-'0';
    int j=s[2]-'0';
    if(j<8)
        j++;
    else if(i<8){
        i++;
        j=1;
    }
    string ans=to_string(i)+'-'+to_string(j);
    cout<< ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    // int t;
    // cin >> t;
    // while (t--) {
        // input
        solve();
    // }

    return 0;
}
