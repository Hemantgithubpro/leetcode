// soln is correct but tle

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    ll n, m, c;
    cin >> n >> m >> c;
    vector<ll> a(n);
    map<ll, ll> pos_count;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pos_count[a[i]]++;
    }
    ll total_sum = 0;
    for (ll i = 0; i < m; i++)
    {
        ll start_pos = i;
        ll people_met = 0;
        ll current_pos = start_pos;
        while (people_met < c)
        {
            current_pos = (current_pos + 1) % m;
            if (pos_count.count(current_pos))
            {
                people_met += pos_count[current_pos];
            }
            if (current_pos == start_pos)
                break;
        }
        total_sum += people_met;
    }
    cout << total_sum << endl;
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
