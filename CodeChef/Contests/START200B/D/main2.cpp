#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mincut(ll a, ll b, ll c, ll d, int k)
{
    if (k < 0)
        return 0;
    ll a0 = a, b0 = a - 1, c0 = c, d0 = c - 1;
    for (ll i = a; i <= b; i++)
    {
        if (!((i >> k) & 1))
            b0 = i;
    }
    for (ll i = c; i <= d; i++)
    {
        if (!((i >> k) & 1))
            d0 = i;
    }
    ll a1 = b0 + 1, c1 = d0 + 1, x = -1, y = -1;
    if (b0 >= a0 && d0 >= c0)
        x = mincut(a0, b0, c0, d0, k - 1);
    if (a1 <= b && c1 <= d)
        y = mincut(a1, b, c1, d, k - 1);
    ll z = (1LL << k);
    if ((b0 >= a0 && c1 <= d) || (a1 <= b && d0 >= c0))
    {
        ll p, q, r, s;
        if (b0 >= a0)
        {
            p = a0;
            q = b0;
        }
        else
        {
            p = a1;
            q = b;
        }

        if (d0 >= c0)
        {
            r = c0;
            s = d0;
        }
        else
        {
            r = c1;
            s = d;
        }
        z += mincut(p, q, r, s, k - 1);
    }
    ll m = -1;
    if (x != -1)
        m = x;
    if (y != -1)
    {
        if (m == -1)
            m = y;
        else
            m = min(m, y);
    }
    if (m == -1)
        return z;
    else
        return min(m, z);
}

ll minsum(ll a, ll b, int k)
{
    if (a > b || k < 0)
        return 0;
    ll e = a - 1;
    for (ll i = a; i <= b; i++)
        if (!((i >> k) & 1))
            e = i;
    ll s = e + 1, res = 0;
    if (e >= a)
        res += minsum(a, e, k - 1);
    if (s <= b)
        res += minsum(s, b, k - 1);
    if (e >= a && s <= b)
        res += (1LL << k) + mincut(a, e, s, b, k - 1);
    return res;
}

void solve()
{
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    int nobits = 0;
    while ((1LL << nobits) <= n)
    {
        nobits++;
    }

    cout << minsum(1, n, nobits) << endl;
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