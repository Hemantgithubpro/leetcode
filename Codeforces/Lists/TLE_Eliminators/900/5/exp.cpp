#include <bits/stdc++.h>
using namespace std;

bool ifallzero(vector<int>&a){
    for (int i = 0; i < a.size(); i++)
    {
        if(a[i]!=0) return false;
    }
    return true;
}

void solve(){
    // change all elements in array to 0
    // operations: at most 8 times
    int n; cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    if(ifallzero(a)) cout<<0;
    else{
            cout<<2<<endl;
            cout<<1<<" "<<n<<endl;
            cout<<1<<" "<<n;
    }
    cout<<endl;

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
