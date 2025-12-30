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

vector<int> cgood(const vector<int> &A, const vector<int> &B)
{
    int n = (int)A.size();
    vector<char> bad(n, 0);
    for (int p = 0; p < n; p++)
    {
        for (int q = 0; q < n; q++)
        {
            if (A[p] >= B[q])
            {
                int s = q - p;
                if (s < 0)
                    s += n;
                bad[s] = 1;
            }
        }
    }
    vector<int> good(n);
    for (int s = 0; s < n; s++)
        good[s] = !bad[s];
    return good;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    cin(a, n);
    cin(b, n);
    cin(c, n);

    vector<int> goodAB = cgood(a, b);
    vector<int> goodBC = cgood(b, c);
    vector<int> goodAC = cgood(a, c);

    vector<int> xs, ys;
    xs.reserve(n);
    ys.reserve(n);
    for (int x = 0; x < n; ++x)
        if (goodAB[x])
            xs.push_back(x);
    for (int y = 0; y < n; ++y)
        if (goodBC[y])
            ys.push_back(y);

    long long cntPairs = 0;
    for (int x : xs)
    {
        for (int y : ys)
        {
            int z = x + y;
            if (z >= n)
                z -= n;
            if (goodAC[z])
                ++cntPairs;
        }
    }

    long long answer = cntPairs * 1LL * n;
    cout << answer << endl;
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