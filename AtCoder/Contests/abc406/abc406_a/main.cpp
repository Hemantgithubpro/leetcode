#include <bits/stdc++.h>
using namespace std;

void solve(int a, int b, int c, int d){
    // deadline-> a:b
    // task completed on -> c:d
    if(a==c){
        if(b>d){
            cout<<"Yes";
        }
        else cout<<"No";
    }
    else if(a>c){
        cout<<"Yes";
    }
    else cout<<"No";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    solve(a,b,c,d);

    return 0;
}
