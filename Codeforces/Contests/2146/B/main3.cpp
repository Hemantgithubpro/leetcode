#include <bits/stdc++.h>
#define ll long long

using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n);
    vector<int> c(m + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        s[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            cin >> s[i][j];
            c[s[i][j]]++;
        }
    }

    bool ac = true;
    for (int i = 1; i <= m; i++)
    {
        if (c[i] == 0)
        {
            ac = false;
            break;
        }
    }
    if (!ac)
    {
        cout << "NO" << endl;
        return;
    }

    vector<bool> f(n, false);
    for (int i = 0; i < n; i++)
    {
        for (int e : s[i])
        {
            if (c[e] == 1)
            {
                f[i] = true;
                break;
            }
        }
    }

    vector<bool> fc(m + 1, false);
    for (int i = 0; i < n; i++)
    {
        if (f[i])
        {
            for (int e : s[i])
            {
                fc[e] = true;
            }
        }
    }

    ac = true;
    for (int i = 1; i <= m; i++)
    {
        if (!fc[i])
        {
            ac = false;
            break;
        }
    }

    if (!ac)
        cout << "YES" << endl;
    else
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (f[i])
                cnt++;
        }
        if (n - cnt >= 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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
