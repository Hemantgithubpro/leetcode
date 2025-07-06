#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    if (n == 1)
    {
        if (x == 0)
            cout << -1 << endl;
        else
            cout << x << endl;
        return;
    }

    int y = __builtin_popcount(x); // COUNT the number of set bits
    if (y > n)
    {
        cout << x << endl;
        return;
    }

    int ans = x + (n - y);
    if ((n - y) % 2 == 1)
    {
        if (x == 0 || x == 1)
            ans += 3;
        else
            ans++;
    }
    cout << ans << endl;
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
