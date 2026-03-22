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
    // this question is basically
    // largest subarray whose sum is equal to k

    int n, k;
    cin >> n >> k;
    vec(arr, n);
    cin(arr, n);

    // prefix sum and hashmap
    map<int, int> mp;

    int sum = 0;
    int maxi = 0;
    bool found = false;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        if (sum == k)
        {
            maxi = i + 1;
            found = true;
        }

        if (mp.find(sum - k) != mp.end())
        {
            maxi = max(maxi, i - mp[sum - k]);
            found = true;
        }

        // store only first occurrence
        if (mp.find(sum) == mp.end())
            mp[sum] = i;
        }

    if (!found)
        cout << -1 << endl;
    else
        cout << n - maxi << endl;
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
