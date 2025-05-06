#include <bits/stdc++.h>
using namespace std;

// time limit exceeded.
int luckiness(int q){
    int maxi=INT_MIN;
    int mini=INT_MAX;
    while(q>0){
        maxi=max(maxi,(q%10));
        mini=min(mini,(q%10));
        q/=10;
    }
    return (maxi-mini);
}

void solve(int a, int b){
    int temp=a;
    int maxi=luckiness(a);
    for(int i=a+1; i<=b; i++){
        if(luckiness(i)>=maxi){
            temp=i;
            maxi=luckiness(i);
        }
    }
    cout<<temp<<endl;
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
        int a;
        cin>>a;
        int b;
        cin>>b;
        solve(a,b);
    }

    return 0;
}
