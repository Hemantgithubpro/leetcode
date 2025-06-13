#include <bits/stdc++.h>
#define ll long long
// well prestest passed, its a first for me, as i guess it's a high division thing.
using namespace std;

void solve()
{
    // input here only
    int n;
    cin >> n;
    int k;
    cin >> k;
    string ans;

    int noof1 = k;
    int noof0 = n - k;
    // ans+='1';
    // noof1--;
    while(noof1--) ans+='1';
    while(noof0--) ans+='0';
    cout<<ans<<endl;
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
