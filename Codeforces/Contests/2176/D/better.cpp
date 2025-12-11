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

const int MOD = 998244353;

struct Edge
{
    int u, v;
    int id;
};

int n, m;
vector<ll> a;
vector<Edge> ed;
vector<vector<int>> adj;
vector<int> memo;
bool cmp(int id1, int id2)
{
    return a[ed[id1].v] < a[ed[id2].v];
}

int lbe(int vertex, ll target)
{
    const vector<int> &lst = adj[vertex];
    int l = 0;
    int r = lst.size();
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (a[ed[lst[mid]].v] < target)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int solve_dp(int edidx)
{
    if (memo[edidx] != -1)
        return memo[edidx];

    int u = ed[edidx].u;
    int v = ed[edidx].v;
    ll target_val = a[u] + a[v];
    ll current_paths = 1;
    int pos = lbe(v, target_val);
    while (pos < adj[v].size())
    {
        int nxt = adj[v][pos];
        if (a[ed[nxt].v] != target_val)
            break;
        current_paths = (current_paths + solve_dp(nxt)) % MOD;
        pos++;
    }
    return memo[edidx] = current_paths;
}
void solve()
{
    cin >> n >> m;
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ed.clear();
    adj.assign(n + 1, vector<int>());
    memo.assign(m, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        ed.pb({u, v, i});
        adj[u].pb(i);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end(), cmp);
    }
    ll total = 0;
    for (int i = 0; i < m; i++)
    {
        total = (total + solve_dp(i)) % MOD;
    }
    cout << total << endl;
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