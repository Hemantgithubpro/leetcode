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

using ull = unsigned long long;

vector<ull> mAnd(vector<ull> &a, vector<ull> &b)
{
    vector<ull> r = a;
    for (int i = 0; i < r.size(); i++)
        r[i] &= b[i];
    return r;
}

bool mEmp(vector<ull> &m)
{
    for (ull x : m)
        if (x)
            return false;
    return true;
}

vector<int> mIdx(vector<ull> &m, int n)
{
    vector<int> r;
    for (int i = 0; i < (int)m.size(); i++)
    {
        ull x = m[i];
        while (x)
        {
            int bit = __builtin_ctzll(x);
            int idx = (i << 6) + bit;
            if (idx < n)
                r.push_back(idx);
            x &= x - 1;
        }
    }
    return r;
}

vector<ull> gOff(vector<int> &X, vector<int> &Y)
{
    int n = (int)X.size();
    int sz = (n + 63) / 64;
    vector<ull> g(sz, ~0ULL);
    if (n % 64)
        g.back() &= (1ULL << (n % 64)) - 1;

    vector<ull> rw(sz);
    for (int t = 0; t < n; ++t)
    {
        fill(rw.begin(), rw.end(), 0ULL);
        for (int o = 0; o < n; ++o)
        {
            if (Y[(t + o) % n] > X[t])
                rw[o >> 6] |= 1ULL << (o & 63);
        }
        g = mAnd(g, rw);
        if (mEmp(g))
            break;
    }
    return g;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;
    for (int &x : c)
        cin >> x;

    vector<ull> m1 = gOff(a, b);
    vector<int> o1 = mIdx(m1, n);

    long long cnt = 0;
    vector<int> b2(n);
    for (int d : o1)
    {
        for (int t = 0; t < n; ++t)
            b2[t] = b[(t + d) % n];
        vector<ull> m2 = gOff(b2, c);
        cnt += (long long)mIdx(m2, n).size();
    }

    cout << cnt * n << '\n';
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