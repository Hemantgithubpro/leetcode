// this is the first solution which i'll see.

// my soln
#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& a){
    // code
    if(n<=2){
        cout<<"yes"<<endl;
        return;
    }
    
    unordered_map<int,int> um;
    for (int i = 0; i < n; i++)
    {
        um[a[i]]++;
    }
    // cout<<um.size();
    if(um.size()==1){
        cout<<"yes"<<endl;
        return;
    }
    if(um.size()>2) cout<<"no"<<endl;
    else{
        vector<int> v;
        for(auto it=um.begin(); it!=um.end(); it++){
            v.push_back(it->first);
        }
        if(abs(um[v[0]]-um[v[1]])>1) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
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

        solve(n, a);
    }

    return 0;
}
