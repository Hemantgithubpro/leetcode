#include <bits/stdc++.h>
using namespace std;
// brute force

bool isValid(int a[], int n, int x){
    int ab=0;
    for(int i=0; i<n; i++){
        ab^=a[i];
    }
    if(ab==x){
        return true;
    }
    return false;
}

int solve(int &n, int &x){
    // vector<int> a(n);
    int a[n];
    for(int i=0; i<n; i++){
        a[i]=i+1;
    }
    do{
        int sum=0;
        if(isValid(a,n,x)){
            for(int i=0; i<n; i++){
                sum+=a[i];
            }
            return sum;
        }
    }
    while(next_permutation(a,a+INT_MAX));
    return -1;
}

int main(){
    int testcases;
    cin>>testcases;
    while(testcases--){
        // input
        int n;
        cin>>n;
        int x;
        cin>>x;
        cout<<solve(n,x)<<endl;
    }
}