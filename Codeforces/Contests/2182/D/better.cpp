#include <bits/stdc++.h>
#define mod 998244353
#define pb push_back
#define asort(a) sort(a.begin(), a.end())
#define vsort(a) sort(a.rbegin(), a.rend())
#define toLow transform(s.begin(), s.end(), s.begin(), ::tolower)
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
#define floop(n) for (int i = 0; i < n; i++)
#define floop2(n) for (int j = 0; j < n; j++)
#define all(a) a.begin(), a.end()
#define vec(a, n) vector<int> a(n)
#define cin(a, n)               \
    for (int i = 0; i < n; i++) \
    cin >> a[i]
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const int N = 1e7 + 10;
using ll = long long;
using namespace std;

vector<ll> fact, invfact;

ll modpow(ll a, ll e)
{
    ll res = 1;
    while (e)
    {
        if (e & 1)
            res = res * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return res;
}

void init_fact(int m)
{
    fact.assign(m + 1, 1);
    invfact.assign(m + 1, 1);
    for (int i = 1; i <= m; i++)
        fact[i] = fact[i - 1] * i % mod;
    invfact[m] = modpow(fact[m], mod - 2);
    for (int i = m; i >= 1; i--)
        invfact[i - 1] = invfact[i] * i % mod;
}

ll nCr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> a[i];

    ll total = accumulate(a.begin(), a.end(), 0LL);
    ll q = total / n;
    int r = int(total % n);

    ll need = 0;
    int low = 0;
    for (int i = 1; i <= n; i++)
    {
        need += max(0LL, q - a[i]);
        low += (a[i] <= q);
    }
    ll spare = a[0] - need;
    if (spare < 0)
        return void(cout << 0 << endl);
    if (r == 0)
        return void(cout << fact[n] << endl);

    ll ways = 0;
    int high = n - low;
    int take = min<int>({r, low, int(min<ll>(spare, r))});
    for (int x = 0; x <= take; x++)
    {
        int y = r - x;
        if (y > high)
            continue;
        ways = (ways + nCr(low, x) * nCr(high, y)) % mod;
    }

    cout << ways * fact[r] % mod * fact[n - r] % mod << endl;
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init_fact(55);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}