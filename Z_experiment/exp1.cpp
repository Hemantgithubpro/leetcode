// cses question
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    long long ans=0;
    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1]){
            long long temp=arr[i]-arr[i+1];
            arr[i+1]+=temp;
            ans+=temp;
        }
    }
    cout<<ans;
    return 0;    
}