#include <bits/stdc++.h>
using namespace std;

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
    // whatever 'n' is, 1...n stays in that position (n-1)! times
    int ans=0;
    vector<int> p(n);
    for(int i=0; i<n; i++){
        p[i] = i+1;    
    }
    reverse(p.begin(), p.end());
    int worst=f(p);
    for(int i=0; i<=worst; i+=2){
        ans++;
    }
    return ans;
}

int main(){
    int testcases;
    cin>>testcases;
    while(testcases--){
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
}