#include <bits/stdc++.h>
#define ll long long

using namespace std;
void solve()
{
    int n, j, k;
    cin >> n >> j >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int maxval = *max_element(a.begin(), a.end());
    if (k > 1)
    {
        cout << "YES\n";
    }
    else
    {
        if (a[j - 1] == maxval)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
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
