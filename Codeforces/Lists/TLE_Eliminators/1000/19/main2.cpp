#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<ll> freq(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> freq[i];
    }

    vector<pair<ll, int>> order;
    order.reserve(n);
    for (int i = 1; i <= n; ++i)
    {
        order.push_back({freq[i], i});
    }
    sort(order.begin(), order.end(), [](const auto &lhs, const auto &rhs)
         { return lhs.first > rhs.first; });

    vector<ll> coords(n + 1, 0);
    ll total = 0;
    ll pos = 1;

    for (int i = 0; i < order.size(); ++i)
    {
        ll coord = (i % 2 == 0) ? pos : -pos;
        if (i % 2 == 1)
        {
            ++pos;
        }
        coords[order[i].second] = coord;
        total += 2LL * order[i].first * llabs(coord);
    }

    cout << total << '\n';
    for (int i = 0; i <= n; ++i)
    {
        cout << coords[i] << (i == n ? '\n' : ' ');
    }
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
