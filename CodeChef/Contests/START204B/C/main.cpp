#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> w(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    unordered_set<int> s(c.begin(), c.end());
    vector<int> colors(s.begin(), s.end());

    unordered_map<int, ll> dp;
    dp[0] = 0;
    for (int i = 0; i + 1 < n; i++)
    {
        unordered_map<int, ll> nd;
        for (auto &p : dp)
        {
            int cur = p.first;
            ll val = p.second;
            ll v = val + (cur == c[i + 1] ? w[i + 1] : -w[i + 1]);
            nd[cur] = max(nd[cur], v);
            for (int nc : colors)
                if (nc != cur)
                {
                    ll vv = val - k + (nc == c[i + 1] ? w[i + 1] : -w[i + 1]);
                    nd[nc] = max(nd[nc], vv);
                }
        }
        dp.swap(nd);
    }

    ll ans = LLONG_MIN;
    for (auto &p : dp)
        ans = max(ans, p.second);
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
