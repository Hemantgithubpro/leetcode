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
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<int> a(m);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());

    struct Friend
    {
        int x;
        ll c;
    };

    vector<Friend> v(n);
    ll base = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        v[i] = {x, (ll)z - y};
        base += y;
    }

    if (base > k)
    {
        cout << 0 << endl;
        return;
    }

    ll extra = k - base;

    ll totalCost = 0;
    for (auto &f : v)
        totalCost += f.c;
    if (totalCost <= extra)
    {
        cout << n << endl;
        return;
    }

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j)
         { return v[i].x < v[j].x; });

    priority_queue<pair<ll, int>> pq;
    int ptr = 0, mtc = 0;
    for (int beauty : a)
    {
        while (ptr < n && v[idx[ptr]].x <= beauty)
        {
            pq.push({v[idx[ptr]].c, idx[ptr]});
            ptr++;
        }
        if (!pq.empty())
        {
            auto [c, id] = pq.top();
            pq.pop();
            v[id].c = -1;
            mtc++;
        }
    }

    vector<ll> rem;
    rem.reserve(n - mtc);
    for (auto &f : v)
        if (f.c >= 0)
            rem.push_back(f.c);

    sort(rem.begin(), rem.end());
    int upg = 0;
    ll spent = 0;
    for (ll c : rem)
    {
        if (spent + c > extra)
            break;
        spent += c;
        upg++;
    }

    cout << mtc + upg << endl;
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