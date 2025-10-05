#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr){
    int n=arr[0];
    int m=arr[1];
    int a=arr[2];
    int b=arr[3];

    int c=max(a,b);
    int d=min(a,b);
    cout<<endl<<endl;
    while(c<=m && n--){
        m-=c;
        cout<<"m:"<<m<<" n:"<<n<<" c:"<<c<<endl;
        // n--;
    }
    while(m>=d && n--){
        m-=d;
        cout<<"m:"<<m<<" n:"<<n<<" d:"<<d<<endl;
    }
    if(m==0 && n==0) cout<<"YES"<<endl;
    else cout<<"No"<<endl;
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
        vector<int> arr(4);
        for (int i = 0; i < 4; i++)
        {
            cin>>arr[i];
        }
        
        solve(arr);
    }

    return 0;
}
