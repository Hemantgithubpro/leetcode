#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sv(ll n)
{
    ll result = 0;
    ll power_of_2 = 1;
    while (n > 0)
    {
        result += power_of_2 * ((n + 1) / 2);
        power_of_2 *= 2;
        n /= 2;
    }
    return result;
}

void solve()
{
    ll n;
    cin >> n;

    if (n == 2)
    {
        cout << 3 << endl;
        return;
    }

    ll svn = sv(n);
    ll cost = 2 * svn - n - 1;
    cout << cost << endl;
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
