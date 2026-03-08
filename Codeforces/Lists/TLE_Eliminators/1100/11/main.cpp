#include <bits/stdc++.h>
#define mod 1000000007
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
#define vec(a, n) vector<ll> a(n)
#define cin(a, n)              \
    for (ll i = 0; i < n; i++) \
    cin >> a[i]
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
// const ll N = 1e7 + 10;
using ll = long long;
using namespace std;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vec(a, n);
    cin(a, n);
    asort(a);
    vector<ll> pref(n + 1, 0);
    for (ll i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];

    ll ans = 0;
    for (ll x = 0; x <= k; x++)
    {
        ll leftRemoved = 2 * x;
        ll rightRemoved = k - x;

        if (leftRemoved + rightRemoved > n)
            continue;

        ll l = leftRemoved;
        ll r = n - rightRemoved;
        ll cur = pref[r] - pref[l];
        ans = max(ans, cur);
    }

    cout << ans << endl;
}
int32_t main()
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
}