#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    int n, m;
    cin >> n >> m;
    if ((n >= 3 && m >= 2) || (n >= 2 && m >= 3))
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
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
