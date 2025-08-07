#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    bool changed = true;
    while (changed)
    {
        changed = false;

        for (int i = 0; i < n - 2; ++i)
        {
            vector<int> kno;
            vector<int> unknown_indices;

            for (int j = 0; j < 3; ++j)
            {
                if (a[i + j] != -1)
                {
                    kno.push_back(a[i + j]);
                }
                else
                {
                    unknown_indices.push_back(i + j);
                }
            }

            if (kno.size() >= 1)
            {
                for (int j = 1; j < kno.size(); ++j)
                {
                    if (kno[j] != kno[0] || kno[j] < 1)
                    {
                        cout << "NO" << endl;
                        return;
                    }
                }

                if (!unknown_indices.empty())
                {
                    int val = kno[0];
                    for (int index : unknown_indices)
                    {
                        if (a[index] == -1)
                        {
                            a[index] = val;
                            changed = true;
                        }
                        else if (a[index] != val)
                        {
                            cout << "NO" << endl;
                            return;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n - 2; ++i)
    {
        if (a[i] != -1 && a[i + 1] != -1 && a[i + 2] != -1)
        {
            if (!(a[i] == a[i + 1] && a[i + 1] == a[i + 2] && a[i] >= 1))
            {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
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
