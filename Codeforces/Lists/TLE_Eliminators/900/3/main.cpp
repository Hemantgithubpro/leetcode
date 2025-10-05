#include <bits/stdc++.h>
using namespace std;

void solve(){
    // code
    long long n,k,x;  cin>>n>>k>>x;
    // cout<<n<<" "<<k<<" "<<x<<endl;
    long long largestsum=(k * (2*n - k + 1)) / 2;
    long long smallestsum=(k*(k+1))/2;
    if(smallestsum<=x && x<=largestsum) cout<<"YES"<<endl;
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
        // input
        solve();
    }

    return 0;
}
