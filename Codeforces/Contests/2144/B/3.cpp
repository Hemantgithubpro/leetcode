#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    int zeros = 0;
    vector<char> present(n + 1, false);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] == 0)
            ++zeros;
        else if (a[i] >= 1 && a[i] <= n)
            present[a[i]] = true;
    }

    // Count prefix of positions already correct (a[i] == i+1)
    int pre = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == i + 1)
            ++pre;
        else
            break;
    }

    // Count suffix of positions already correct (a[i] == i+1)
    int suf = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] == i + 1)
            ++suf;
        else
            break;
    }

    int ans = n - pre - suf;

    if (zeros == 0)
    {
        cout << max(0, ans) << '\n';
        return;
    }

    if (zeros == 1)
    {
        int missing = 0, zpos = -1;
        for (int v = 1; v <= n; ++v)
            if (!present[v])
            {
                missing = v;
                break;
            }
        for (int i = 0; i < n; ++i)
            if (a[i] == 0)
            {
                zpos = i;
                break;
            }
        if (zpos + 1 == missing)
            --ans;
    }

    cout << max(0, ans) << '\n';
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
        solve();
    }

    return 0;
}
