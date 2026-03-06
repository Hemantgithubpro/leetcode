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
    vec(a, n);
    cin(a, n);

    vector<ll> psum(n);
    psum[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        psum[i] = psum[i - 1] + a[i];
    }

    // values of k are divisors of n,

    // calculate max diff of k=1,2,3...

    ll ans = 0;
    for (int k = 1; k <= n / 2; k++)
    {
        if (n % k)
            continue;
        // sliding window of size k
        ll start = k - 1;
        ll maxi = psum[start];
        ll mini = psum[start];
        ll res = 0;
        for (ll idx = start + k; idx < n; idx += k)
        {                                        // Iterate over trucks
            ll curr = psum[idx] - psum[idx - k]; // Calculate current truck's weight
            maxi = max(maxi, curr);              // Update maximum weight
            mini = min(mini, curr);              // Update minimum weight
        }
        ans = max(ans, maxi - mini); // Update the maximum absolute difference
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