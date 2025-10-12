#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<ll> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<int> a(n);
    int next_val = 1;
    a[0] = next_val;
    next_val++;
    for (int i = 1; i < n; i++)
    {
        ll d = b[i] - b[i - 1];
        ll p = (i + 1) - d;
        if (p == 0)
        {
            a[i] = next_val;
            next_val++;
        }
        else
            a[i] = a[p - 1];
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
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
