#include <bits/stdc++.h>
using namespace std;

// ans=n(n-1)/2, where n is the number of dominoes

// sort(dominoes.begin(), dominoes.end(), [](const vector<int>& a, const vector<int>& b) {
//     return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
// });
int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    // TC: O(n)

    unordered_map<int,int> mpp;
    for(auto &d: dominoes){
        int x=min(d[0],d[1]);
        int y=max(d[0],d[1]);
        mpp[x*10+y]++;
    }
    int ans=0;
    for(auto &d: mpp){
        int n=d.second;
        ans+=n*(n-1)/2;
    }
    return ans;
}

int main(){
    vector<vector<int>> dominoes={{1,2},{2,1},{3,4},{5,6}};
    cout<<numEquivDominoPairs(dominoes)<<endl; // 1
}