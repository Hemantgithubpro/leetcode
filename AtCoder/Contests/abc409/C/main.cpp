#include <bits/stdc++.h>
using namespace std;

void solve(){
    // code
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int l;
    cin>>l;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    unordered_map<int,int> um;
    // vector<vector<int>> a;

    um[0]++;    // first place is always occupied
    int newplace=0;
    for (int i = 1; i < n; i++)
    {
        newplace=(newplace+v[i])%l;
        um[newplace]++;
    }


    // double eqdist=(4/3)*l;
    // eqdist=eqdist/(pow(3,0.5));
    // eqdist=eqdist/3.14;
    // cout<<eqdist;


    // gap is related to l only.
    if(l%3==0) int gap=l/3;
    else{
        cout<<0;
        return 0;
    }

    int ans=0;
    // it will run 'gap' times
    for(auto it=um.begin(); it!=um.end(); it++){

    }


    return 0;
}
