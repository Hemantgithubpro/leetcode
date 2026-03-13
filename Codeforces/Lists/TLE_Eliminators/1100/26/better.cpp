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
const int N = 1e7 + 10;
using ll = long long;
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    vec(a, n);
    cin(a, n);

    // prefix sum
    vector<ll> psum(n, 0);
    psum[0] = a[0];
    for (ll i = 1; i < n; i++)
    {
        psum[i] = psum[i - 1] + a[i];
    }

    // two pointer
    ll l = 0, r = n - 1;
    ll sumall = psum[r];
    ll summid = sumall / 2;
    ll mid = l + (r - l) / 2;
    while (l < r)
    {
        if (psum[mid] == summid)
            break;
        else if (psum[mid] > summid)
            r = mid - 1;
        else
            l = mid + 1;

        mid = l + (r - l) / 2;
    }

    ll sum1 = 0, sum2 = 0;
    l = mid;
    r = mid + 1;
    while (l >= 0 && r < n)
    {
        sum1 = psum[l];
        sum2 = sumall - psum[r - 1];
        if (sum1 == sum2)
            break;

        if (sum1 > sum2)
        {
            sum1 -= a[l];
            l--;
        }
        else
        {
            sum2 -= a[r];
            r++;
        }
    }

    cout << (l+1) + (n-r) << endl;
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