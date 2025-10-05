#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll count_non_good(ll lim)
{
    if (!lim)
        return 0;
    vector<ll> p = {2, 3, 5, 7};
    ll cnt = 0;

    for (int i = 1; i < 16; ++i)
    {
        ll prod = 1;
        int bits = 0;

        for (int j = 0; j < 4; ++j)
        {
            if ((i >> j) & 1)
            {
                if (p[j] > lim / prod)
                {
                    prod = lim + 1;
                    break;
                }
                prod *= p[j];
                bits++;
            }
        }

        if (prod <= lim)
            if (bits & 1)
                cnt += lim / prod;
            else
                cnt -= lim / prod;
    }
    return cnt;
}

void solve()
{
    ll l, r;
    cin >> l >> r;
    cout << (r - l + 1) - (count_non_good(r) - count_non_good(l - 1)) << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}