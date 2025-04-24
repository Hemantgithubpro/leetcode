#include <bits/stdc++.h>
using namespace std;

bool ifallneg(int *b, int n){
    for(int i=0; i<n; i++){
        if(b[i]>=0) return false; 
    }
    return true;
}

bool iscomplementary(int *arr1, int* arr2, int n, int fixed){
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
            ans = max(0, k-mini+1); // Fix: changed to k-mini+1 instead of k-(maxi-mini)+1
        }
        else{
            int fixed=-1; // Initialize with invalid value
            bool validFixed = false;
            
            for(int i=0; i<n; i++){
                if(b[i]>=0){
                    fixed=a[i]+b[i];
                    validFixed = true;
                    break;
                }
            }
            
            if(validFixed && fixed<=k){
                bool valid = true;
                for(int i=0; i<n; i++){
                    if(b[i]>=0 && a[i]+b[i]!=fixed){
                        valid = false;
                        break;
                    }
                    else if(b[i]<0){
                        // Check if complementary value would be non-negative
                        if(fixed-a[i] < 0){
                            valid = false;
                            break;
                        }
                    }
                }
                
                if(valid){
                    // Create a copy to test modifications
                    int temp_b[n];
                    for(int i=0; i<n; i++){
                        temp_b[i] = (b[i]<0) ? (fixed-a[i]) : b[i];
                    }
                    
                    if(iscomplementary(a,temp_b,n,fixed)) ans=1;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}