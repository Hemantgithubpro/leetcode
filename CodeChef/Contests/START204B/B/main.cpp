#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<int> cnt(m, 0);
    ll curr = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        curr += a[i];
        cnt[a[i]]++;
    }

    ll mini = curr;

    for (ll k = 1; k < m; k++)
    {
        ll w = (m - k) % m;
        curr += n;
        if (cnt[w] > 0)
        {
            curr -= m * cnt[w];
        }
        mini = min(mini, curr);
    }

    cout << mini << endl;
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
