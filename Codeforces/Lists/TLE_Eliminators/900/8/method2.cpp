#include <bits/stdc++.h>
using namespace std;

void solve(){
    // code
    int n; cin>>n;
    vector<char> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    
    int continousl=0,continousr=0;
    int templ=0,tempr=0;

    for(int i=1; i<n; i++){
        if(v[i]=='<' && v[i-1]=='<') templ++;
        else templ=0;
        continousl=max(continousl,templ);
    }
    for(int i=1; i<n; i++){
        if(v[i]=='>' && v[i-1]=='>') tempr++;
        else tempr=0;
        continousr=max(continousr,tempr);
    }
    
    int ans=max(continousl,continousr)+2;
    cout<<ans<<endl;
    
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
