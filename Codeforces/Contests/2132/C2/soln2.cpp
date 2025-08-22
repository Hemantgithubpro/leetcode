#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll MAX_IDX = 40;
ll p[MAX_IDX + 2];
ll cval[MAX_IDX + 1];

void precompute()
{
    p[0] = 1;
    for (ll i = 1; i <= MAX_IDX + 1; ++i)
        p[i] = p[i - 1] * 3;

    cval[0] = 3;
    for (ll i = 1; i <= MAX_IDX; ++i)
        cval[i] = p[i + 1] + i * p[i - 1];
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    ll tmp = n;
    ll sumdig = 0;
    while (tmp > 0)
    {
        sumdig += tmp % 3;
        tmp /= 3;
    }
    if (sumdig > k)
    {
        cout << -1 << '\n';
        return;
    }
    if (k >= n)
    {
        cout << 3 * n << '\n';
        return;
    }

    vector<ll> d;
    tmp = n;
    while (tmp > 0)
    {
        d.push_back(tmp % 3);
        tmp /= 3;
    }

    ll L = d.size();
    ll cost = 0;
    ll deals = 0;

    for (ll i = 0; i < L; ++i)
    {
        cost += 1LL * d[i] * cval[i];
        deals += d[i];
    }

    for (ll i = L - 1; i >= 1; --i)
    {
        ll canUse = (k - deals) / 2;
        if (canUse <= 0)
            break;
        ll take = min<ll>(d[i], canUse);
        if (take == 0)
            continue;
        d[i] -= take;
        d[i - 1] += 3 * take;
        deals += 2 * take;
        cost += take * (-cval[i] + 3 * cval[i - 1]);
    }

    cout << cost << '\n';
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

    precompute();
    int t;
    cin >> t;
    while (t--)
    {
        // ll n;
        // cin>>n;
        // vector<ll> a(n);
        // for (ll i = 0; i < n; i++)
        // {
        //     cin>>a[i];
        // }
        // solve(n,a);

        solve();
    }

    return 0;
}
