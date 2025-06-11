#include <bits/stdc++.h>
using namespace std;
// with this code, its tle.

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
        long long n;
        cin>>n;
        long long k;
        cin>>k;
        // while(n%k!=0 && n>=0){
        //     n-=2;
        // }
        
        if(n%2==1){
            if(k%2==1) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
        else{
            cout<<"yes"<<endl;
        }
        // if(n%k==0) cout<<"yes"<<endl;
        // else if(n==0) cout<<"yes"<<endl;
        // else cout<<"no"<<endl;
        // solve();
    }

    return 0;
}
