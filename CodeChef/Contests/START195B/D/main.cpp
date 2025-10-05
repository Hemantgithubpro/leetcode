#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> get_divisors(ll n)
{
    vector<ll> divisors;
    if (n == 1)
    {
        divisors.push_back(1);
        return divisors;
    }
    ll sqrt_n = sqrt(n);
    for (ll i = 1; i <= sqrt_n; i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
            if (i != n / i)
            {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        ll N;
        cin >> N;

        vector<ll> divisors = get_divisors(N);
        ll max_k = min(200000LL, (ll)(2 * sqrt((double)N) + 100));

        ll ans = -1;
        for (ll k = 1; k <= max_k; k++)
        {
            ll k_odd = (k + 1) / 2;
            ll k_even = k / 2;
            ll Fmin = k_odd * (k_even + 1);

            if (Fmin > N)
            {
                if (k >= 62)
                    break;
                else
                    continue;
            }

            if (k < 62)
            {
                ll x_min = k_odd;
                ll x_max = (k_odd > 0) ? (1LL << (k_odd - 1)) : 1;
                if (x_max > N)
                    x_max = N;

                ll y_min = k_even + 1;
                ll y_max = (k_even > 0) ? (1LL << k_even) : 1;
                if (y_max > N)
                    y_max = N;

                auto it_low = lower_bound(divisors.begin(), divisors.end(), x_min);
                auto it_high = upper_bound(divisors.begin(), divisors.end(), x_max);
                for (auto it = it_low; it != it_high; it++)
                {
                    ll a = *it;
                    if (a > x_max)
                        break;
                    if (N % a != 0)
                        continue;
                    ll b = N / a;
                    if (b >= y_min && b <= y_max)
                    {
                        ans = k;
                        goto found;
                    }
                }
            }
            else
            {
                ll L = k_odd;
                ll R = (k_even + 1) > 0 ? N / (k_even + 1) : N;
                if (L > R)
                    continue;

                auto it = lower_bound(divisors.begin(), divisors.end(), L);
                if (it != divisors.end() && *it <= R)
                {
                    ans = k;
                    goto found;
                }
            }
        }

    found:
        if (ans == -1)
            cout << "-1\n";
        else
            cout << ans << '\n';
    }
    return 0;
}