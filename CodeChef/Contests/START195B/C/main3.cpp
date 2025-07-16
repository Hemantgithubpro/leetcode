#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll INF = LLONG_MIN;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<ll> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j >= 1; --j)
        {
            if (dp[j - 1] != INF)
            {
                dp[j] = max(dp[j], dp[j - 1] + a[i]);
            }
        }
    }

    vector<ll> bonus_prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        bonus_prefix_sum[i] = bonus_prefix_sum[i - 1] + (i - 1);
    }

    auto get_bonus = [&](int j, int c2)
    {
        if (c2 == 0)
            return 0LL;
        return bonus_prefix_sum[j] - bonus_prefix_sum[j - c2];
    };

    vector<ll> ans_exact(2 * n + 1, 0);
    for (int j = 1; j <= n; ++j)
    {
        if (dp[j] == INF)
        {
            continue;
        }
        for (int c2 = 0; c2 <= j; ++c2)
        {
            int k = j + c2;
            if (k > 2 * n)
            {
                break;
            }
            ll bonus = get_bonus(j, c2);
            ll current_sum = dp[j] + bonus;
            ans_exact[k] = max(ans_exact[k], current_sum);
        }
    }

    for (int k = 1; k <= 2 * n; ++k)
    {
        ans_exact[k] = max(ans_exact[k - 1], ans_exact[k]);
    }

    for (int k = 1; k <= 2 * n; ++k)
    {
        cout << ans_exact[k] << " ";
    }
    cout << "\n";
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
