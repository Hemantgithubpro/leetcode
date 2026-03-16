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

    ll ans = 0;

    // Iterate over powers of 2 from 2^1 to 2^60
    for (int i = 1; i <= 60; i++)
    { // 2^1 -> 2^60

        // Set to store distinct values after mod operation
        set<ll> distinctVals;
        // Calculate k as 2^i
        ll k = 1LL << i; // Time Complexity: O(1)

        // Calculate a[i] % k for each element and insert into the set
        for (int ind = 0; ind < n; ind++)
        {
            distinctVals.insert(a[ind] % k); // Time Complexity: O(log N)
        } 

        // Check if there are exactly 2 distinct values
        if (distinctVals.size() == 2)
        {
            ans = k;
            break;
        }
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
