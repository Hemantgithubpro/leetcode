#include <bits/stdc++.h>
using namespace std;

void solve(){
    // a: max value of timer, b: intial value of timer
    int a,b,n; cin>>a>>b>>n;
    // int arr[n]; 
    vector<pair<int,bool>> x(n); 
    for (int i = 0; i < n; i++)
    {
        cin>>x[i].first;
        x[i].second=true;    // can be used= true, if used= false
    }

    int time=b;
    while(b--){ // timer is running, for every second
        for(int i=0; i<n; i++){
            
        }
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
        solve();
    }

    return 0;
}
