#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    string a;
    cin >> n >> a;
    ll ans = 0;
    if (n == 1)
        ans = (a[0] - '0');
    else
    {
        ans += 2LL * (a[0] - '0');
        ans += 2LL * (a[n - 1] - '0');
        for (int i = 1; i <= n - 2; i++)
        {
            ans += 3LL * (a[i] - '0');
        }
    }
    cout << ans << '\n';
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
