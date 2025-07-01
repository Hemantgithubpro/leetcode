#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> freq(n + 2, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] <= n)
        {
            freq[a[i]]++;
        }
    }

    vector<bool> can(n + 3, false);
    can[0] = true;
    int M = 0;
    for (int m = 1; m <= n + 1; m++)
    {
        if (freq[m - 1] > 0)
        {
            can[m] = true;
            M = m;
        }
        else
        {
            break;
        }
    }

    vector<int> diff(n + 2, 0);
    for (int m = 0; m <= M; m++)
    {
        int L = freq[m];
        int R = n - m;
        if (L <= R)
        {
            diff[L]++;
            if (R + 1 <= n + 1)
            {
                diff[R + 1]--;
            }
        }
    }

    vector<int> ans(n + 1);
    ans[0] = diff[0];
    for (int k = 1; k <= n; k++)
    {
        ans[k] = ans[k - 1] + diff[k];
    }

    for (int k = 0; k <= n; k++)
    {
        cout << ans[k];
        if (k < n)
        {
            cout << ' ';
        }
    }
    cout << endl;
}

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
