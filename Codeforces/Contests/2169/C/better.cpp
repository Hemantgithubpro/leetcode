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
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<ll> Pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        Pre[i] = Pre[i - 1] + a[i - 1];
    }

    ll total_sum = Pre[n];
    ll max_candidate = -1e18;
    ll cur_max_G = -1e18;

    for (int j = 0; j < n; j++)
    {
        ll G_j = -(ll)j * j - j + Pre[j];
        if (G_j > cur_max_G)
        {
            cur_max_G = G_j;
        }
        ll F_j = (ll)j * j + 3 * j + 2 - Pre[j + 1];
        ll candidate = F_j + cur_max_G;
        if (candidate > max_candidate)
        {
            max_candidate = candidate;
        }
    }

    ll gain = max(0LL, max_candidate);
    cout << total_sum + gain << endl;
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