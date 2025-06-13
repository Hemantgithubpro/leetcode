#include <bits/stdc++.h>
using namespace std;

void solve(){
    // code
    int a,b;
    cin>>a>>b;
    // a in one direc and b in other

    int xk,yk; cin>>xk>>yk;
    int xq,yq; cin>>xq>>yq;
    // coordinated of king and queen

    // i've to find the no. of positions from which knight can attack both king and queen, meaning the places which overlap from king and queen's position if knight was in their position
    int ans=0;
    // now to try all positions which knight try
    if((xk+a)==(xq-b) && (yk+b)==(yq-a)) ans++;
    if((xk+a)==(xq-b) && (yk-b)==(yq+a)) ans++;
    if((xk-a)==(xq+b) && (yk-b)==(yq+a)) ans++;
    if((xk-a)==(xq+b) && (yk+b)==(yq-a)) ans++;
    if((xk+b)==(xq-a) && (yk+a)==(yq-b)) ans++;
    if((xk+b)==(xq-a) && (yk-a)==(yq+b)) ans++;
    if((xk-b)==(xq+a) && (yk-a)==(yq+b)) ans++;
    if((xk-b)==(xq+a) && (yk+a)==(yq-b)) ans++;

    // if(xk+a==xq+b && xk+b==xq+a) ans++;
    // if(xk-a==xq-b && xk+b==xq+a) ans++;
    // if(xk+a==xq+b && xk-b==xq-a) ans++;
    // if(xk-a==xq-b && xk-b==xq-a) ans++;

    cout<<ans<<endl;
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
        solve();
    }

    return 0;
}
