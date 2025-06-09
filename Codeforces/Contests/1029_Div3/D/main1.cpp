#include <bits/stdc++.h>
using namespace std;

bool isdecreasing(vector<int>& arr){
    for(int i=1;i<arr.size(); i++){
        if(arr[i-1]<arr[i]) return false;
    }
    return true;
}
bool isincreasing(vector<int>& arr){
    for(int i=1;i<arr.size(); i++){
        if(arr[i-1]>arr[i]) return false;
    }
    return true;
}

void solve(int n, vector<int>& arr){
    // code
    if(n==2){
        if(arr[0]==arr[1]){
            cout<<"NO"<<endl;
            return;
        }
        else if(isdecreasing(arr)){
            if(arr[0]==2*arr[1]){
                cout<<"YES"<<endl;
                return;
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
        else if(isincreasing(arr)){
            if(2*arr[0]==arr[1]){
                cout<<"YES"<<endl;
                return;
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    else{

        if(isdecreasing(arr) || isincreasing(arr)){
            int diff=arr[1]-arr[0];
            for(int i=2; i<n; i++){
                if(arr[i]-arr[i-1]!=diff){
                    cout<<"NO"<<endl;
                    return;
                }
            }
            cout<<"YES"<<endl;
            
        }
        else cout<<"NO"<<endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    int t;
    cin >> t;
    while (t--) {
        // input
        int n;
        cin>>n; 
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        solve(n,a);
    }

    return 0;
}
