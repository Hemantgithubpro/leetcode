#include <bits/stdc++.h>
using namespace std;

// did on my own
// 1. check if sum is divisible by 3
// 2. check if a[0] and a[1] are equal, if not, transfer from a[2] to a[0] and a[1]
// 3. check if a[2] is less than a[0] and a[1], if not, transfer from a[2] to a[0] and a[1]


bool isValid(vector<int> &a){
    return (a[0]==a[1] && a[1]==a[2]);
}

string solve(vector<int> &a){
    if((a[0]+a[1]+a[2])%3!=0){
        return "NO";
    }
    int k=a[1]-a[0];
    a[2]-=k;
    a[0]+=k;
    if(a[2]<0 || a[0]<0 || a[1]<0){
        return "NO";
    }
    if(a[2]<a[1] || a[1]<a[0]){
        return "NO";
    }
    // if(a[2]%3==0 && a[2]/3==a[0]){
    //     return "YES";
    // }
    
    return "YES";
}

int main(){
    int testcases;
    cin>>testcases;
    for(int i=0; i<testcases; i++){
        vector<int> a(3);
        for(int j=0; j<3; j++){
            cin>>a[j];
        }
        cout<<solve(a)<<endl;
    }
}