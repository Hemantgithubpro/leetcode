#include <bits/stdc++.h>
#define ll long long

using namespace std;
struct Edge
{
    int u, v;
    ll w;
    bool operator<(Edge const &o) const { return w < o.w; }
};
struct DSU
{
    vector<int> p, sz;
    DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (sz[a] < sz[b])
            swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
    int size(int x) { return sz[find(x)]; }
};
void solve(int cs)
{
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    if (N == 0)
    {
        cout << "Case #" << cs++ << ": 0\n";
        return;
    }
    vector<Edge> e;
    e.reserve(2 * N);
    for (int i = 0; i < N - 1; ++i)
        e.push_back({i + 1, i + 2, A[i] > A[i + 1] ? A[i] - A[i + 1] : A[i + 1] - A[i]});
    for (int i = 0; i < N; ++i)
        e.push_back({i + 1, 0, A[i]});
    sort(e.begin(), e.end());
    DSU d(N + 1);
    ll ans = 0;
    for (auto &ed : e)
    {
        if (d.find(ed.u) != d.find(ed.v))
        {
            d.unite(ed.u, ed.v);
            ans = ed.w;
            if (d.size(0) == N + 1)
                break;
        }
    }
    cout << "Case #" << cs++ << ": " << ans << "\n";
}

// void solve(ll n, vector<ll>& a){

// }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int i = 1;
    while (t--)
    {
        // ll n;
        // cin>>n;
        // vector<ll> a(n);
        // for (int i = 0; i < n; i++)
        // {
        //     cin>>a[i];
        // }
        // solve(n,a);

        solve(i);
        i++;
    }

    return 0;
}
