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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> nxt(n + 2, vector<int>(k + 1, n + 1));
    for (int i = n; i >= 1; i--)
        for (int v = 1; v <= k; v++)
            nxt[i][v] = a[i] >= v ? i : nxt[i + 1][v];
    using P = pair<int, ll>;
    vector<vector<vector<P>>> dp(k + 1, vector<vector<P>>(k + 1));
    dp[0][0].push_back({0, 0});
    ll ans = 0;
    for (int cost = 0; cost <= k; cost++)
    {
        for (int val = 0; val <= cost; val++)
        {
            for (auto st : dp[cost][val])
            {
                int idx = st.first;
                ll pen = st.second;
                ans = max(ans, (ll)val * (n + 1) - pen);
                for (int nv = val + 1; nv <= k - cost; nv++)
                {
                    int start = idx + 1;
                    if (start > n)
                        break;
                    int p = nxt[start][nv];
                    if (p > n)
                        continue;
                    int nc = cost + nv;
                    ll np = pen + 1LL * (nv - val) * p;
                    P ns = {p, np};
                    auto &vlist = dp[nc][nv];
                    bool dom = false;
                    for (auto &e : vlist)
                        if (e.first <= p && e.second <= np)
                        {
                            dom = true;
                            break;
                        }
                    if (dom)
                        continue;
                    vector<P> tmp;
                    for (auto &e : vlist)
                        if (!(p <= e.first && np <= e.second))
                            tmp.push_back(e);
                    tmp.push_back(ns);
                    vlist.swap(tmp);
                }
            }
        }
    }
    cout << ans << "\n";
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