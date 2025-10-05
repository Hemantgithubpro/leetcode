#include <bits/stdc++.h>
using namespace std;

int findnoof1(int num, int digits){
    int noof1=0;
    for(int j=0; j<digits; j++){
        if(num%2){
            noof1++;
            num/=10;
        }
        else num/=10;
    }
    return noof1;
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int sizeoftest=0;
        cin>>sizeoftest;
        int test=0;
        cin>>test;
        // 101
        int noof1=findnoof1(test,sizeoftest);
        int noof0=sizeoftest-noof1;
        int ans=0;
        ans=noof1*sizeoftest - (noof1-noof0);
        // for(int k=0; k<sizeoftest; k++){
        //     if(test&(1<<k)) ans+=noof1-1;
        //     else ans+=noof1+1;
        // }
        cout<<ans<<endl;
    }
}