#include <bits/stdc++.h>
using namespace std;
// brute force solution

int f(int &n, long long &factorial){
    unordered_set<int> ans;
    // for(long long i=1; i<=factorial; i++){
    for(int i=1; i<=factorial; i++){
        for(int j=i+1; j<=n; j++){
            // cout<<i<<" "<<j<<endl;
            // cout<<factorial<<" "<<i<<" "<<j<<endl;
            ans.insert((factorial/(i*j)));
        }

    }
    return ans.size();
}

int solve(int &n){
    unordered_set<int> ans;
    long long factorial = 1;
    int t=n;
    while(t > 1){
        factorial *= t;
        t--;
    }
    // vector<int> p(n);
    // for(int i=0; i<n; i++){
        // p[i] = i+1;    
    // }

    ans.insert(f(n, factorial));
        
    return ans.size();
}

int main(){
    int testcases;
    cin>>testcases;
    while(testcases--){
        int n;
        cin>>n;
        // cout<<solve(n)<<endl;
        cout<<"ans: "<<solve(n)<<endl;
    }
}