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

bool isSorted(vector<int> &a, int l, int r)
{
    for (int i = l; i < r; i++)
    {
        if (a[i + 1] < a[i])
            return false;
    }
    return true;
}

void solve()
{
    // find the longest sorted subarray
    int n;
    cin >> n;
    vec(a, n);
    cin(a, n);
    vec(b, n);
    cin(b, n);
    if (isSorted(b, 0, n - 1))
    {
        cout << 1 << ' ' << n << endl;
        return;
    }
    int ans = 0;
    int x = 0;
    int y = 0;

    int l = 0, r = 0;
    while (l < n && r < n)
    {
        while (l < n - 1 && b[l + 1] < b[l])
            l++;
        if (l > n - 1)
        {
            cout << -1 << endl;
            return;
        }

        r = l + 1;
        while (r < n - 1 && b[r + 1] >= b[r])
            r++;
        int temp = ans;
        ans = max(ans, r - l + 1);
        if (ans != temp)
        {
            x = l;
            y = r;
        }
        l = r;
    }
    cout << x + 1 << ' ' << y + 1 << endl;
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