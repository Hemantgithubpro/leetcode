#include <bits/stdc++.h>
using namespace std;

string ans(string s){
    if(s.size() <= 10) return s;
    else {
        return s[0] + to_string(s.size() - 2) + s.back();
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        cout<<ans(s)<<endl;
    }
}