#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

ll power(ll base, ll exp)
{
    ll res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modinv(ll n)
{
    return power(n, MOD - 2);
}

void solve()
{
    int n;
    cin >> n;
    int ones = 0;
    bool h = false;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
            ones++;
        else
            h = true;
    }

    if (!h)
    {
        if (ones % 2 == 1)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    else
        cout << modinv(2) << endl;
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
