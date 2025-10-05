#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;

// Fast modular exponentiation
ll pow_mod(ll base, ll exp, ll mod)
{
    base %= mod;
    ll res = 1;
    while (exp > 0)
    {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

void solve()
{
    // Read input
    ll n, m;
    cin >> n >> m;

    // Store events for DP
    vector<vector<pair<ll, ll>>> events(m + 1);
    ll coef = 1;

    for (ll i = 0; i < n; i++)
    {
        ll l, r, p, q;
        cin >> l >> r >> p >> q;

        // Calculate probability values
        ll inv_q = pow_mod(q, MOD - 2, MOD);
        ll p_ex = (p * inv_q) % MOD;
        ll p_nex = (1 - p_ex + MOD) % MOD;
        ll inv_nex = pow_mod(p_nex, MOD - 2, MOD);
        ll val = (p_ex * inv_nex) % MOD;

        // Update coefficient
        coef = (coef * p_nex) % MOD;

        // Add event at the end of segment
        if (r <= m)
        {
            events[r].push_back({l, val});
        }
    }

    // DP array
    vector<ll> dp(m + 1, 0);
    dp[0] = 1;

    // Fill DP table
    for (ll i = 1; i <= m; i++)
    {
        for (auto &e : events[i])
        {
            ll l = e.first;
            ll v = e.second;

            if (l - 1 >= 0)
            {
                dp[i] = (dp[i] + dp[l - 1] * v) % MOD;
            }
        }
    }

    // Calculate final answer
    ll ans = (coef * dp[m]) % MOD;
    ans = (ans % MOD + MOD) % MOD; // Ensure positive
    std::cout << ans << std::endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
