#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> sets(n);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        sets[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            cin >> sets[i][j];
        }
    }

    vector<vector<int>> elset(m + 1);
    for (int i = 0; i < n; i++)
    {
        for (int x : sets[i])
        {
            elset[x].push_back(i);
        }
    }

    for (int i = 1; i <= m; i++)
    {
        if (elset[i].empty())
        {
            cout << "NO" << endl;
            return;
        }
    }

    if (n <= 22)
    {
        int ways = 0;
        for (int mask = 1; mask < (1 << n); mask++)
        {
            vector<bool> covered(m + 1, false);
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    for (int x : sets[i])
                    {
                        covered[x] = true;
                    }
                }
            }

            bool valid = true;
            for (int i = 1; i <= m; i++)
            {
                if (!covered[i])
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
            {
                ways++;
                if (ways >= 3)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        if (ways >= 3)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        return;
    }

    vector<bool> mand(n, false);
    for (int i = 1; i <= m; i++)
    {
        if (elset[i].size() == 1)
        {
            mand[elset[i][0]] = true;
        }
    }

    vector<bool> cov(m + 1, false);
    for (int i = 0; i < n; i++)
    {
        if (mand[i])
        {
            for (int x : sets[i])
            {
                cov[x] = true;
            }
        }
    }

    vector<int> rem;
    for (int i = 1; i <= m; i++)
    {
        if (!cov[i])

            rem.push_back(i);
    }

    if (rem.empty())
    {
        int red = 0;
        for (int i = 0; i < n; i++)
        {
            if (!mand[i])
                red++;
        }
        if (red >= 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return;
    }

    int flex = 0;
    for (int x : rem)
    {
        if (elset[x].size() > 1)
            flex++;
    }

    if (flex >= 3)
        cout << "YES" << endl;
    else
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
