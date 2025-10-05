#include <bits/stdc++.h>
using namespace std;

string solve(vector<int>& q){
    if(q.size()!=2) return "NO";
    if((q[1]-q[0])>1) return "YES";
    return "NO";
}

int main(){
    int testcases;
    cin>>testcases;
    for(int i=0; i<testcases; i++){
        int n;
        cin>>n;
        vector<int> a;
        for(int j=0; j<n; j++){
            int k;
            cin>>k;
            a.push_back(k);
        }
        cout<<solve(a)<<endl;
    }
}