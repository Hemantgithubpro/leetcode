#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool isc(const vector<vector<int>> &s, int a, int b, int m)
{
    vector<char> c(m + 1, 0);
    int cnt = 0;
    for (int x : s[a])
        if (!c[x])
        {
            c[x] = 1;
            cnt++;
        }
    for (int x : s[b])
        if (!c[x])
        {
            c[x] = 1;
            cnt++;
        }
    return cnt == m;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n);
    vector<int> f(m + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        s[i].resize(l);
        for (int j = 0; j < l; j++)
        {
            cin >> s[i][j];
            f[s[i][j]]++;
        }
    }
    for (int i = 1; i <= m; i++)
        if (f[i] == 0)
        {
            cout << "NO" << endl;
            return;
        }
    int red = 0;
    for (int i = 0; i < n; i++)
    {
        bool ok = true;
        for (int x : s[i])
            if (f[x] == 1)
            {
                ok = false;
                break;
            }
        if (ok)
            red++;
    }
    if (red >= 2)
    {
        cout << "YES" << endl;
        return;
    }
    if (n >= 3 && (isc(s, 0, 1, m) || isc(s, 0, 2, m) || isc(s, 1, 2, m)))
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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
