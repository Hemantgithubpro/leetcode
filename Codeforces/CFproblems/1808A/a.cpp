#include <bits/stdc++.h>
using namespace std;

// did it.
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
        // luckiness(60)=6, 60++=6--,
        // luckiness(55)=0, 55++=0++
        // luckiness(56)=1, 56++=1++
        // luckiness(59)=4, 59++=4+2
        if(luckiness(i)>=maxi){
            temp=i;
            maxi=luckiness(i);
        }
        if(luckiness(i)==9){
            temp=i;
            break;
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
