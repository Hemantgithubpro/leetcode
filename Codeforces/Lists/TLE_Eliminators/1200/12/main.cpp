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

void solve()
{
    // sum of all x[i] values in the group must not exceed the sum of y[i] values in the group
    // in a group min. 2 persons, to find max no. of groups?
    // can leave some people from the group
    int n;
    cin >> n;
    vec(x, n);
    cin(x, n);
    vec(y, n);
    cin(y, n);
    ll maxcount = n / 2;

    vec(sur, n);
    floop(n)
    {
        sur[i] = y[i] - x[i];
    }
    // extra budget or in debt for each i
    asort(sur);

    vector<pair<int, int>> vp(n);
    floop(n)
    {
        vp[i] = {x[i], y[i]};
    }
    sort(vp.begin(), vp.end());

    // two pointer,
    // max spend with min spend guy
    // or max budget with min budget guy
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
