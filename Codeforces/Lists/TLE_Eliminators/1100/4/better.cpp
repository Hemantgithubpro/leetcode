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

    ll ans = LLONG_MIN;
    if (n == 1)
    {
        cout << a[0] << endl;
        return;
    }
    // brute force, without dp, non-recursive solution
    // for (int i = 0; i < n - 1; i++)
    // {
    //     int sum = a[i];
    //     ans = max(sum, ans);
    //     bool flag = false; // even = false
    //     if (a[i] & 1)
    //         flag = true; // odd = true
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (!(a[j] & 1) == flag)
    //         {
    //             sum += a[j];
    //             flag = !flag;
    //             ans = max(sum, ans);
    //         }
    //         else
    //         break;
    //     }
    //     ans = max(sum, ans);
    // }

    ll cur = a[0];
    ans = a[0];

    // simple kadane's algo
    for (int i = 1; i < n; i++)
    {
        bool prevOdd = (abs(a[i - 1]) & 1);
        bool curOdd = (abs(a[i]) & 1);

        if (prevOdd != curOdd)
            cur = max((ll)a[i], cur + a[i]);
        else
            cur = a[i];

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