#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> &a){
    long long all=1;
    vector<long long> beforek;
    vector<long long> afterk1;
    for (int i = 0; i < n; i++)
    {
        all*=a[i];
    }
    long long temp1=1;
    long long temp2=all;
    for (int i = 0; i < n; i++)
    {
        
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
        // input
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        solve(n,a);
    }

    return 0;
}
