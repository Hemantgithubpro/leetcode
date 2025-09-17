#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> b = v;
    bool ok = true;
    for (int k = n; k >= 1; k--)
    {
        int l = -1, r = -1, c = 0;
        for (int i = 0; i < n; i++)
        {
            if (b[i] > 0)
            {
                if (l == -1)
                    l = i;
                r = i;
                c++;
            }
        }
        if (c == 0 || c != k || r - l + 1 != k)
        {
            ok = false;
            break;
        }
        for (int i = l; i <= r; i++)
            b[i]--;
    }
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
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
