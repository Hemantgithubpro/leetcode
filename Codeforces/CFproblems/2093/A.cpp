#include <bits/stdc++.h>
using namespace std;

string yesorno(int k){
    if(k%2) return "YES";
    return "NO";
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        cout<<yesorno(k)<<endl;
    }
}