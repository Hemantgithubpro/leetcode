#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> p10(20); // powers of 10 precomputed

ll sumUpTo(ll x)
{
    if (x <= 0)
        return 0;
    ll res = 0;
    ll b = 1;
    while (b <= x)
    {
        ll nb = b * 10;
        ll q = x / nb;
        ll rm = x % nb;
        ll dg = rm / b;
        res += q * b * 45;
        res += (dg * (dg - 1)) / 2 * b;
        res += dg * (rm % b + 1);
        b = nb;
    }
    return res;
}
void solve()
{
    ll k;
    cin >> k;
    ll len = 1;
    ll st = 1;
    ll tot = 0;
    while (k > tot + len * 9 * st)
    {
        tot += len * 9 * st;
        len += 1;
        st *= 10;
    }
    ll rem = k - tot;
    ll cnt = rem / len;
    ll remd = rem % len;

    ll ans = 0;
    for (int i = 1; i < len; i++)
    {
        ll gs = p10[i - 1];
        ll ge = p10[i] - 1;
        ans += sumUpTo(ge) - sumUpTo(gs - 1);
    }
    if (cnt > 0)
    {
        ans += sumUpTo(st + cnt - 1) - sumUpTo(st - 1);
    }
    if (remd > 0)
    {
        ll cur = st + cnt;
        string s = to_string(cur);
        for (int i = 0; i < remd; i++)
        {
            ans += s[i] - '0';
        }
    }
    cout << ans << endl;
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

    p10[0] = 1;
    for (int i = 1; i < 20; i++)
    {
        p10[i] = p10[i - 1] * 10;
    }
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
