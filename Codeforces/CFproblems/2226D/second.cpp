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
    vector<int> a(n);
    bool is_sorted = true;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i > 0 && a[i] < a[i - 1])
        {
            is_sorted = false;
        }
    }

    if (is_sorted)
    {
        yes;
        return;
    }

    int m0 = 1e9, M0 = -1e9;
    int m1 = 1e9, M1 = -1e9;
    bool has0 = false, has1 = false;

    for (int x : a)
    {
        if (x % 2 == 0)
        {
            has0 = true;
            m0 = min(m0, x);
            M0 = max(M0, x);
        }
        else
        {
            has1 = true;
            m1 = min(m1, x);
            M1 = max(M1, x);
        }
    }

    if (!has0 || !has1)
    {
        no;
        return;
    }

    int first_even_greater = 1e9, last_even_smaller = -1e9;
    int first_odd_greater = 1e9, last_odd_smaller = -1e9;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            if (a[i] > M1 && first_even_greater == 1e9)
                first_even_greater = i;
            if (a[i] < m1)
                last_even_smaller = i;
        }
        else
        {
            if (a[i] > M0 && first_odd_greater == 1e9)
                first_odd_greater = i;
            if (a[i] < m0)
                last_odd_smaller = i;
        }
    }

    if (first_even_greater < last_even_smaller || first_odd_greater < last_odd_smaller)
    {
        no;
    }
    else
    {
        yes;
    }
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
