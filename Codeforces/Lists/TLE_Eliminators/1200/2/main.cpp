#include <bits/stdc++.h>
using ll = long long;
#define mod 1000000007
#define pb push_back
#define asort(a) sort(a.begin(), a.end())
#define vsort(a) sort(a.rbegin(), a.rend())
#define toLow transform(s.begin(), s.end(), s.begin(), ::tolower)
#define floop(n) for (int i = 0; i < n; i++)
#define floop2(n) for (int j = 0; j < n; j++)
#define all(a) a.begin(), a.end()
#define vec(a, n) vector<ll> a(n)
#define cin(a, n)               \
    for (int i = 0; i < n; i++) \
    cin >> a[i]
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const int N = 1e7 + 10;
using namespace std;

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

bool verify(vector<ll> &a, ll k)
{
    if (k <2)
        return false;
    set<ll> us;
    for (int i = 0; i < a.size(); i++)
    {
        ll val = a[i];
        ll temp = val % k;
        us.insert(temp);
    }
    if (us.size() == 2)
        return true;
    return false;
}

void solve()
{
    ll n;
    cin >> n;
    vec(a, n);
    cin(a, n);

    asort(a);

    vec(diff, n);
    for (int i = 0; i < n - 1; i++)
    {
        ll temp = a[i + 1] - a[i];
        diff[i] = temp;
    }

    for (int i = 0; i < diff.size(); i++)
    {
        ll val = abs(diff[i]);
        if (verify(a, val))
        {
            cout << val << endl;
            return;
        }
    }

    cout << 2 << endl;
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
