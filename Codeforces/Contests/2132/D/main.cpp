#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll pow10[20];

void precompute()
{
    pow10[0] = 1;
    for (int i = 1; i < 20; i++)
    {
        pow10[i] = pow10[i - 1] * 10;
    }
}

ll digit_sum_up_to(ll n)
{
    if (n <= 0)
        return 0;
    ll ans = 0;
    ll base = 1;
    while (base <= n)
    {
        ll next_base = base * 10;
        ll full = n / next_base;
        ll rem = n % next_base;
        ll digit = rem / base;
        ans += full * base * 45;
        ans += (digit * (digit - 1)) / 2 * base;
        ans += digit * (rem % base + 1);
        base = next_base;
    }
    return ans;
}
ll group_sum(int d)
{
    if (d == 1)
        return 45;
    return 45 * pow10[d - 1] + 405 * (d - 1) * pow10[d - 2];
}
void solve()
{
    // input here only
    ll k;
    cin >> k;
    ll total = 0;
    ll d = 1;
    ll start = 1;
    while (k > d * 9 * start)
    {
        total += group_sum(d);
        k -= d * 9 * start;
        d++;
        start *= 10;
    }

    ll n = k / d;
    ll r = k % d;
    ll last_full = start + n - 1;
    if (n > 0)
    {
        total += digit_sum_up_to(last_full) - digit_sum_up_to(start - 1);
    }
    if (r > 0)
    {
        ll num = start + n;
        string s = to_string(num);
        for (int i = 0; i < r; i++)
        {
            total += s[i] - '0';
        }
    }
    cout << total << endl;
}

// void solve(ll n, vector<ll>& a){

// }

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
        // ll n;
        // cin>>n;
        // vector<ll> a(n);
        // for (int i = 0; i < n; i++)
        // {
        //     cin>>a[i];
        // }
        // solve(n,a);

        solve();
    }

    return 0;
}
