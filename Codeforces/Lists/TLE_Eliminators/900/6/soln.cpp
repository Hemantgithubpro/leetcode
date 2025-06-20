#include <bits/stdc++.h>
using namespace std;

void solve(){
    // code
    long long n; cin>>n;
    
    int count=0;
    for (long long i = 1; i <= n; i++)
    {
        if(n%i!=0) {
            break;
        }
        count++;
    }
    cout<<count<<endl;
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
