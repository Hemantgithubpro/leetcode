#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll g(ll K)
{
    if (K == 0)
        return 0;
    if (((K + 1) & K) == 0)
    {
        ll m = 0;
        ll t = K + 1;
        while (t > 1)
        {
            m++;
            t >>= 1;
        }
        return m * (1LL << (m - 1));
    }
    ll m = 1;
    while (m * 2 <= K)
    {
        m *= 2;
    }
    return g(m - 1) + g(K - m) + m;
}

ll f(ll n)
{
    if (n == 1)
        return 0;
    ll m = 1;
    while (m * 2 <= n)
    {
        m *= 2;
    }
    if (n == m)
        return f(m - 1) + m + 1;
    else
        return f(m - 1) + g(n - m) + m;
}

void solve()
{
    ll n;
    cin >> n;
    cout << f(n) << endl;
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