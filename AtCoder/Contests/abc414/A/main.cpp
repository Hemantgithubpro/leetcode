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
    // int t;
    // cin >> t;
    // while (t--) {
    //     // input
    //     solve();
    // }

    int n,l,r; cin>>n>>l>>r;
    int count=0;
    while(n--){
        int x,y; cin>>x>>y;
        if(x<=l && y>=r) count++;
    }
    cout<<count;
    return 0;
}
