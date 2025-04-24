#include <bits/stdc++.h>
using namespace std;

bool ifallneg(int *b, int n){
    for(int i=0; i<n; i++){
        if(b[i]>=0) return false; 
    }
    return true;
}

bool iscomplementry(int *arr1, int* arr2, int n, int fixed){
    for(int i=0; i<n; i++){
        if(arr2[i]<0) return false;
        if(arr1[i]+arr2[i]!=fixed) return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        int k;
        cin>>k;
        int a[n];
        int b[n];
        int ans=0;
        for(int j=0; j<n; j++){
            cin>>a[j];
        }
        for(int j=0; j<n; j++){
            cin>>b[j];
        }
        if(ifallneg(b,n)){
            int mini=INT_MAX;
            for(int i=0; i<n; i++) mini=min(mini,a[i]);
            int maxi=INT_MIN;
            for(int i=0; i<n; i++) maxi=max(maxi,a[i]);
            int temp=maxi-mini;
            ans=k-temp+1;
        }
        else{
            int fixed=0;
            for(int i=0;i<n; i++){
                if(b[i]>=0){
                    fixed=a[i]+b[i];
                    break;
                }
            }
            if(fixed<=k){
                for(int i=0; i<n; i++){
                    if(b[i]<0) b[i]=fixed-a[i];
                }
                if(iscomplementry(a,b,n,fixed)) ans=1;
            }
        }
        cout<<ans<<endl;
    }
}