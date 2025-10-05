#include <bits/stdc++.h>
using namespace std;
// brute force solution

int f(vector<int> &p){
    int ans=0;
    for(int i=1; i<=p.size(); i++){
        if((p[i-1]-i)>=0){
            ans += (p[i-1]-i);
        }else{
            ans += (i-p[i-1]);
        }
    }
    return ans;
}

int solve(int &n){
    unordered_set<int> ans;
    // long long factorial = 1;
    // int t=n;
    // while(t > 1){
    //     factorial *= t;
    //     t--;
    // }
    vector<int> p(n);
    for(int i=0; i<n; i++){
        p[i] = i+1;    
    }

    do{
        ans.insert(f(p));
    }
    while(next_permutation(p.begin(), p.end()));    
    return ans.size();
}

int main(){
    int testcases;
    cin>>testcases;
    while(testcases--){
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
        // cout<<"ans: "<<solve(n)<<endl;
    }
}