#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        ll base = 0;
        vector<int> P, N;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                base += a[i];
                P.push_back(i);
            }
            else
            {
                base -= a[i];
                N.push_back(i);
            }
        }

        ll within_max = 0;
        if (P.size() >= 2)
        {
            within_max = max(within_max, (ll)P.back() - P[0]);
        }
        if (N.size() >= 2)
        {
            within_max = max(within_max, (ll)N.back() - N[0]);
        }

        if (P.empty() || N.empty())
        {
            cout << base << '\n';
            continue;
        }

        vector<ll> F, G;
        for (int i : P)
        {
            F.push_back(i - 2 * a[i]);
            G.push_back(2 * a[i] + i);
        }

        int k = P.size();
        vector<ll> right_max_F(k);
        vector<ll> left_min_G(k);
        right_max_F[k - 1] = F[k - 1];
        for (int i = k - 2; i >= 0; i--)
        {
            right_max_F[i] = max(F[i], right_max_F[i + 1]);
        }
        left_min_G[0] = G[0];
        for (int i = 1; i < k; i++)
        {
            left_min_G[i] = min(G[i], left_min_G[i - 1]);
        }

        ll between_max = LLONG_MIN;
        for (int j : N)
        {
            auto it = lower_bound(P.begin(), P.end(), j);
            if (it != P.end())
            {
                int pos = it - P.begin();
                ll candidate = right_max_F[pos] + (2 * a[j] - j);
                between_max = max(between_max, candidate);
            }
            it = lower_bound(P.begin(), P.end(), j);
            if (it != P.begin())
            {
                int pos = it - P.begin() - 1;
                ll candidate = (2 * a[j] + j) - left_min_G[pos];
                between_max = max(between_max, candidate);
            }
        }

        ll ans = base;
        if (within_max > 0)
        {
            ans = base + within_max;
        }
        if (between_max > LLONG_MIN && between_max > 0)
        {
            ans = max(ans, base + between_max);
        }
        cout << ans << '\n';
    }
    return 0;
}