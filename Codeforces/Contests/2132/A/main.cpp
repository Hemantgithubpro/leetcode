#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    int na;
    cin >> na;
    string a;
    cin >> a;
    int m;
    cin >> m;
    string b, c;
    cin >> b >> c;

    for (int i = 0; i < m; i++)
    {
        if (c[i] == 'D')
            a += b[i];
        else
        {
            string temp = "";
            temp += b[i];
            temp += a;
            a = temp;
        }
    }
    cout << a << endl;
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
