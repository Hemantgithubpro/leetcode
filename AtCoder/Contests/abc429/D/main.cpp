#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, m, c;
    cin >> n >> m >> c;
    vector<ll> a(n);
    map<ll, ll> cnt;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    vector<pair<ll, ll>> pos;
    for (auto &p : cnt)
    {
        pos.push_back({p.first, p.second});
    }
    sort(pos.begin(), pos.end());

    ll k = pos.size();

    vector<ll> prefix(2 * k + 1, 0);
    for (int i = 0; i < 2 * k; i++)
    {
        prefix[i + 1] = prefix[i] + pos[i % k].second;
    }

    ll sum = 0;

    for (int i = 0; i < k; i++)
    {
        ll left = i, right = i + k;
        ll met = 0;

        while (left < right)
        {
            ll mid = (left + right) / 2;
            ll total = prefix[mid + 1] - prefix[i];

            if (total >= c)
                right = mid;
            else
                left = mid + 1;
        }

        if (left < i + k)
            met = prefix[left + 1] - prefix[i];
        else
            met = prefix[i + k] - prefix[i];

        ll sp = pos[i].first;
        ll pp = (i == 0) ? pos[k - 1].first : pos[i - 1].first;

        ll rc;
        if (i == 0)
            rc = sp + (m - pp);
        else
            rc = sp - pp;

        sum += met * rc;
    }

    cout << sum << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--) {
    // input
    solve();
    // }

    return 0;
}
