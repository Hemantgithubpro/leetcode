#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
}

int finddigits(int n)
{
    int a = 0;
    while (n){
        n=n/10;
        a++;
    }
    return a;
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
        int n;
        cin >> n;
        int ans = 0;
        int digits=finddigits(n);
        if(digits==1){
            ans=n;
        }
        else if(digits==2){
            ans+=9;
            n=n/10;
            ans+=n;
        }else if(digits==3){
            ans+=9*2;
            n=n/100;
            ans+=n;
        }else if(digits==4){
            ans+=9*3;
            n=n/1000;
            ans+=n;
        }else if(digits==5){
            ans+=9*4;
            n=n/10000;
            ans+=n;
        }else if(digits==6){
            ans+=9*5;
            n=n/100000;
            ans+=n;
        }
        
        cout << ans << endl;
        solve();
    }

    return 0;
}
