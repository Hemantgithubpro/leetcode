#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    int n;
    cin >> n;
    string s;
    cin >> s;
    // shift only in the format 1 1 0, and if no1<2 then its easy
    int no1 = 0;
    int no0 = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = s[i] - '0';
        if (temp == 0)
            no0++;
        else
            no1++;
    }
    if(no1==1){
        cout<<1<<endl;
        return;
    }
    if(no1==0||no1==0){
        cout<<0<<endl;
        return;
    }

    for(int i=0; i<n; i++){
        
    }
}

// void solve(ll n, vector<ll>& a){

// }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        // ll n;
        // cin>>n;
        // vector<ll> a(n);
        // for (int i = 0; i < n; i++)
        // {
        //     cin>>a[i];
        // }
        // solve(n,a);

        solve();
    }

    return 0;
}
