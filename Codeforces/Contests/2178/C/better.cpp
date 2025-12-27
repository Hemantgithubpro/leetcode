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
#define vec(a, n) vector<int> a(n)
#define cin(a, n)               \
    for (int i = 0; i < n; i++) \
    cin >> a[i]
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const int N = 1e7 + 10;
using ll = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1), psum(n + 1, 0), pneg(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
        pneg[i] = pneg[i - 1] + (a[i] < 0 ? -a[i] : 0);
    }

    vector<ll> dp(n + 1, 0);
    ll ans = LLONG_MIN;

    ans = max(ans, dp[1] - (psum[n] - psum[1]));

    ll best = dp[1] + a[1] - pneg[1];
    for (int k = 2; k <= n; k++)
    {
        dp[k] = best + pneg[k - 1];
        ans = max(ans, dp[k] - (psum[n] - psum[k]));
        best = max(best, dp[k] + a[k] - pneg[k]);
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