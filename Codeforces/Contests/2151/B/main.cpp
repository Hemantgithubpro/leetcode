#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair<int, int> find_int(set<pair<int, int>> &iv, int x)
{
    auto it = iv.upper_bound({x, INT_MAX});
    if (it == iv.begin())
        return {INT_MIN, INT_MIN};
    it--;
    if (it->second < x)
        return {INT_MIN, INT_MIN};
    return *it;
}

void add_pt(set<pair<int, int>> &iv, int x)
{
    if (find_int(iv, x).first != INT_MIN)
        return;
    auto l = find_int(iv, x - 1), r = find_int(iv, x + 1);
    if (l.first != INT_MIN && r.first != INT_MIN)
    {
        iv.erase(l);
        iv.erase(r);
        iv.insert({l.first, r.second});
    }
    else if (l.first != INT_MIN)
    {
        iv.erase(l);
        iv.insert({l.first, x});
    }
    else if (r.first != INT_MIN)
    {
        iv.erase(r);
        iv.insert({x, r.second});
    }
    else
        iv.insert({x, x});
}

int nxt_white(set<pair<int, int>> &iv, int x)
{
    int y = x + 1;
    auto p = find_int(iv, y);
    if (p.first == INT_MIN)
        return y;
    else
        return p.second + 1;
}

void solve()
{
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    set<int> bc(a.begin(), a.end());
    set<pair<int, int>> iv;
    if (m)
    {
        sort(a.begin(), a.end());
        int st = a[0], en = a[0];
        for (int i = 1; i < m; i++)
        {
            if (a[i] == en + 1)
                en = a[i];
            else
            {
                iv.insert({st, en});
                st = en = a[i];
            }
        }
        iv.insert({st, en});
    }
    for (int i = 1; i <= n; i++)
    {
        int x = 1;
        for (int j = 0; j < i; j++)
        {
            if (s[j] == 'A')
                x++;
            else
                x = nxt_white(iv, x);
        }
        bc.insert(x);
        add_pt(iv, x);
    }
    cout << bc.size() << '\n';
    for (int c : bc)
        cout << c << ' ';
    cout << '\n';
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

        solve();
    }

    return 0;
}
