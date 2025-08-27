#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int a,b; cin>>a>>b;
    int temp=b/2;
    int c=min(a,temp);
    cout<<3*c<<endl;
}

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
