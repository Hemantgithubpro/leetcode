#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& a){
    // this question is basically counting number of odds and number of evens

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
        cin >> n;
        vector<int> a(n);
        int noofodd=0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i]%2==1) noofodd++;
        }
        if(noofodd%2==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        // solve(n,a);
    }

    return 0;
}
