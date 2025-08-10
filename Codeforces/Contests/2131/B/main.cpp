#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    int n;
    cin >> n;

    if (n % 2 != 0)
    {
        int pairs = (n - 1) / 2;
        for (int i = 0; i < pairs; ++i)
        {
            cout << -1 << " " << 3 << " ";
        }
        cout << -1 << endl;
    }
    else
    {
        int pairs = (n - 2) / 2;
        for (int i = 0; i < pairs; ++i)
        {
            cout << -1 << " " << 3 << " ";
        }
        cout << -1 << " " << 2 << endl;
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
