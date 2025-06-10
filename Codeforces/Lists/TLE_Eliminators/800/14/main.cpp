#include <bits/stdc++.h>
using namespace std;

void solve(int a, int b, int c)
{
    // Anna: a,c
    // Katie: b,c
    // first turn is anna's, after anna: c-1, after katie: c-2, ... c=0
    if(c%2==0){ // anna will now exhaust a
        a--;
        if(a>=b) cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
    else{   // katie will now exhaust b

        if(a>=b) cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        // input

        int a, b, c;
        cin >> a >> b >> c;

        solve(a, b, c);
    }

    return 0;
}
