#include <bits/stdc++.h>
using namespace std;


// it'll definetely give tle
void solve(){
    // code
    int count=1;
    long long n; cin>>n;
    // find divisors
    vector<long long> divisors;
    for (long long i = 1; i <= n; i++)
    {
        if(n%i==0) divisors.push_back(i);
    }
    
    int maxLen = 1;  // to store maximum length
    int currLen = 1; // to store current streak length
    
    for (int i = 1; i < divisors.size(); i++) {
        if (divisors[i] == divisors[i-1] + 1) {
            currLen++;
        } else {
            currLen = 1;
        }
        maxLen = max(maxLen, currLen);
    }
    
    cout << maxLen << "\n";
    
    
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
