#include <bits/stdc++.h>
#define ll long long

using namespace std;
bool is_cons(const vector<ll> &a, int s, int e)
{
    if (s >= e)
        return true;
    for (int i = s; i < e; i++)
        if (a[i + 1] != a[i] + 1)
            return false;
    return true;
}

bool is_b_pref(const vector<ll> &a, int ss, ll ks, ll nm)
{
    ll ck = ks, cn = 1;
    for (ll i = ss; i < a.size(); i++)
    {
        if (ck > nm || a[i] != cn)
            return false;
        cn++;
        if (cn > ck)
        {
            ck++;
            cn = 1;
        }
    }
    return true;
}

void solve()
{
    ll n;
    int m;
    cin >> n >> m;
    vector<ll> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    ll cnt = 0;
    if (is_cons(a, 0, m - 1))
    {
        ll mv = a[0] + m - 1;
        if (n >= mv)
            cnt += n - mv + 1;
    }
    for (int p = 1; p < m; p++)
    {
        if (is_cons(a, 0, p - 1))
        {
            ll k = a[p - 1];
            if (k < n && is_b_pref(a, p, k + 1, n))
                cnt++;
        }
    }
    cout << cnt << endl;
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
