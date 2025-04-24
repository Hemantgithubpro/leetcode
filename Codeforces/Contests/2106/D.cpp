#include <bits/stdc++.h>
using namespace std;
// time was less.
int func(int *arr1,int n1, int *arr2, int n2){
    int ans=-1;
    for(int i=0; i<n1; i++){
        int j=0;
        if(arr1[i]>=arr2[j]) j++;
        if(j==n2) return 0;
    }


    
    
    return ans;
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int n1;
        cin>>n1;
        int arr1[n1];
        
        int n2;
        cin>>n2;
        int arr2[n2];
        
        cout<<func(arr1,n1,arr2,n2)<<endl;
    }
}