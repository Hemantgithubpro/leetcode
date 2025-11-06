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
    int n, m, killed_count = 0;
    cin >> n >> m;
    multiset<ll> swords;
    for (int i = 0; i < n; ++i)
    {
        ll a;
        cin >> a;
        swords.insert(a);
    }

    vector<pair<ll, ll>> monsters(m);
    for (int i = 0; i < m; ++i)
        cin >> monsters[i].first;
    for (int i = 0; i < m; ++i)
        cin >> monsters[i].second;

    sort(monsters.begin(), monsters.end(), [](auto &x, auto &y)
         { return x.second > y.second || (x.second == y.second && x.first < y.first); });

    for (auto &[health, reward] : monsters)
    {
        auto it = swords.lower_bound(health);
        if (it != swords.end())
        {
            killed_count++;
            ll sword_used = *it;
            swords.erase(it);
            if (reward > 0)
                swords.insert(max(sword_used, reward));
        }
    }

    cout << killed_count << endl;
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