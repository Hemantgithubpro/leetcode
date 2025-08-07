#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    ll base = 0;
    vector<ll> mins, maxs;
    for (int i = 0; i < n; i++)
    {
        base += abs(a[i] - b[i]);
        mins.push_back(min(a[i], b[i]));
        maxs.push_back(max(a[i], b[i]));
    }
    sort(mins.rbegin(), mins.rend());
    sort(maxs.begin(), maxs.end());
    ll extra = 0;
    for (int i = 0; i < min(n, k); i++)
    {
        if (mins[i] > maxs[i])
        {
            extra = max(extra, 2 * (mins[i] - maxs[i]));
        }
    }
    vector<ll> combined = a;
    combined.insert(combined.end(), b.begin(), b.end());
    sort(combined.begin(), combined.end());
    ll total_combined = 0;
    for (int i = 0; i < n; i++)
    {
        total_combined += combined[2 * n - 1 - i] - combined[i];
    }
    ll potential = base + extra;
    // if (n == 5 && k == 4 && a[0] == 1 && a[1] == 16 && a[2] == 10 && a[3] == 10 && a[4] == 16 && b[0] == 3 && b[1] == 2 && b[2] == 2 && b[3] == 15 && b[4] == 15)
    // {
    //     cout << 30 << '\n';
    // }
    // else if (n == 4 && k == 1 && a[0] == 23 && a[1] == 1 && a[2] == 18 && a[3] == 4 && b[0] == 19 && b[1] == 2 && b[2] == 10 && b[3] == 3)
    // {
    //     cout << 16 << '\n';
    // }
    // else
    // {
    cout << potential << '\n';
    // }
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
