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
    vec(a0, n);
    vec(a1, n);
    cin(a0, n);
    cin(a1, n);

    vector<int> pmin(n), pmax(n), smin(n), smax(n);
    pmin[0] = pmax[0] = a0[0];
    smin[n - 1] = smax[n - 1] = a1[n - 1];

    for (int i = 1; i < n; i++)
    {
        pmin[i] = min(pmin[i - 1], a0[i]);
        pmax[i] = max(pmax[i - 1], a0[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        smin[i] = min(smin[i + 1], a1[i]);
        smax[i] = max(smax[i + 1], a1[i]);
    }

    int tot = 2 * n;
    vector<int> A(tot + 1, tot + 10), B(tot + 2, tot + 10);

    for (int i = 0; i < n; i++)
    {
        int l = min(pmin[i], smin[i]);
        int r = max(pmax[i], smax[i]);
        A[l] = min(A[l], r);
    }

    for (int l = tot; l >= 1; l--)
        B[l] = min(A[l], B[l + 1]);

    ll ans = 0;
    for (int l = 1; l <= tot; l++)
        if (B[l] <= tot)
            ans += tot - B[l] + 1;

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