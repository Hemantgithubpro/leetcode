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
    int n, q;
    cin >> n >> q;
    vec(a, n);
    cin(a, n);
    ll sum = 0;
    floop(n) { sum += a[i]; }

    bool issecond = false;
    bool prevwas2 = false;
    ll secondval = 0;
    int secondtime = -1;
    vector<int> updatedtime(n, -1);
    for (int cnt = 0; cnt < q; cnt++)
    {
        int temp;
        cin >> temp;
        if (temp == 1)
        {
            // a[i-1] = x
            int i, x;
            cin >> i >> x;

            --i;
            ll oldVal = a[i];
            if (issecond && (prevwas2 || updatedtime[i] < secondtime))
                oldVal = secondval;

            sum += 1LL * x - oldVal;
            a[i] = x;
            updatedtime[i] = cnt;
            prevwas2 = false;
        }
        else
        {
            // a[all] = x;
            int x;
            cin >> x;
            issecond = true;
            prevwas2 = true;
            secondval = x;
            secondtime = cnt;
            sum = 1LL * x * n;
            // floop(n) a[i] = x;
        }
        cout << sum << endl;
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
    // int t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }
}
