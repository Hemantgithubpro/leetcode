#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n; cin>>n;
    vector<ll> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<pair<ll,int>> days;
    for (int i = 1; i <= n; i++) days.emplace_back(a[i], i);
    sort(days.rbegin(), days.rend());
    ll sold = 0;
    ll profit = 0;
    for (auto &p : days) {
        ll price = p.first;
        int day = p.second;
        ll available = day - sold;
        if (available <= 0) continue;
        ll take = min(2LL, available);
        profit += take * price;
        sold += take;
        if (sold >= n) break;
    }

    cout << profit << '\n';
}

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
        solve();
    }

    return 0;
}
