#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<pair<int, int>> s(n);
    for (int i = 0; i < n; i++)
        s[i] = {a[i], i};
    sort(s.begin(), s.end());

    vector<ll> ans(n);
    if (n > 0)
        ans[s[0].second] = -1;
    if (n > 1)
        ans[s[n - 1].second] = -1;

    for (int i = 1; i < n - 1; i++)
    {
        ll lm = (ll)(s[i - 1].first + s[i].first);
        ll rm = (ll)(s[i].first + s[i + 1].first);
        ll lb = lm / 2 + 1, ub = rm / 2;
        ans[s[i].second] = ub - lb + 1;
    }

    vector<ll> f(n);
    for (int i = 0; i < n; i++)
        f[s[i].second] = ans[s[i].second];

    for (int i = 0; i < n; i++)
    {
        cout << f[i] << " ";
    }
    cout << "\n";
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
