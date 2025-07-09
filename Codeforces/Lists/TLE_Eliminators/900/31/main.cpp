#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    if (n % 3 > 0 || n % 2 == 0)
    {
        cout << -1 << endl;
        return;
    }

    int ans = 0;
    while (n > 1 && n % 3 == 0)
    {
        n = n / 3;
        ans += 2;
    }
    if (n != 1)
        cout << -1 << endl;
    else
        cout << ans << endl;
    // int quo = n / 3;
    // int ans = quo * 2;
    // cout << ans << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        // input
        solve();
    }

    return 0;
}
