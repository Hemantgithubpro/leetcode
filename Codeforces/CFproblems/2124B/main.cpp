#include <bits/stdc++.h>
#define ll long long

using namespace std;

// void solve(){
//     // input here only

// }

void solve(ll n, vector<ll> &a)
{
    ll sum = a[0] + min(a[0], a[1]);
    ll ans = a[0] + a[1];

    ll mindiff = LLONG_MAX;

    for (int i = 2; i < n; i++)
    {
        if (a[i - 1] >= a[i - 2])
        {
            ans = min(ans, sum);
            break;
        }
        mindiff = min(mindiff, a[i - 2] - a[i - 1]);
        ans = min(ans, sum + (min(mindiff, a[i])));
    }

    ll ans2 = 0;
    ll mini = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, a[i]);
        ans2 += mini;
    }
    cout << min(ans, ans2) << endl;
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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        solve(n, a);

        // solve();
    }

    return 0;
}
