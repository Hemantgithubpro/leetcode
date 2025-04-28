#include <bits/stdc++.h>
using namespace std;
// 2104A_4 worked, and i did it on my own
bool isValid(vector<int> &a){
    return (a[0]==a[1] && a[1]==a[2]);
}

string solve(vector<int> &a){
    // while(a[2]>a[0] && a[2]>a[1]){
            

    //     // if(a[0]<a[1]){
    //     //     a[0]++;
    //     // }else{
    //     //     a[1]++;
    //     // }
    //     // a[2]--;
    // }
    int k=a[1]-a[0];
    a[2]-=k;
    a[0]+=k;
    if(a[2]<0 || a[0]<0 || a[1]<0){
        return "NO";
    }
    if(a[2]<a[1] || a[1]<a[0]){
        return "NO";
    }
    if(isValid(a)){
        return "YES";
    }
    // if(a[2]%3==0 && a[2]/3==a[0]){
    //     return "YES";
    // }
    if(a[2]%3==0){
        return "YES";
    }
    // 12 20 30
    // 20 20 22
    // 20 20 24
    // 20 20 23
    // 2*a[0] +1 == a[2]
    // a[2]-2
    // a[0]++
    // 20 20 26
    // 3 5 10
    // 5 5

    // 
    // while(a[2]>a[0] && a[2]>a[1]){
    //     a[0]++;
    //     a[1]++;
    //     a[2]-=2;
    //     if(isValid(a)){
    //         return "YES";
    //     }
    // }

    // a[0], a[2]

    
    return "NO";
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