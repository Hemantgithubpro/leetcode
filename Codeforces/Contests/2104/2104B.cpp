#include <bits/stdc++.h>
using namespace std;

int findmax(vector<int> &a, int n){
    int max=0;
    for(int i=0; i<n; i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}

// finding sum from last
int findsum(vector<int> &a, int n){
    int sum=0;
    for(int i=n-1; i>=0; i--){
        sum+=a[i];
    }
}

vector<int> solve(vector<int> &a, int n){
    for(int k=0; k<n; k++){
        int sum=0;
        int maxi=findmax(a,n-k);

    }
}

int main(){
    int testcases;
    cin>>testcases;
    for(int i=0; i<testcases; i++){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int j=0; j<n; j++){
            cin>>a[j];
        }
        vector<int> result = solve(a,n);
        for(int j=0; j<result.size(); j++){
            cout<<result[j]<<" ";
        }
        cout<<endl;
    }
}