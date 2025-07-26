#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll lowerbinarysearch(vector<ll> a, ll target)
{
    // finding strictly lower than target in sorted array a
    ll n = a.size();
    ll l = 0, r = a.size() - 1;
    ll idx = -1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (a[mid] < target)
        {
            idx = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return idx;
}

void solve()
{
    // input here only
    ll n, d;
    cin >> n >> d;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    ll ans = 0;
    ll idx = lowerbinarysearch(a, d);
    ans += n - idx - 1;
    ll i = 0, j = idx;
    while (j > i && i < n && j >= 0)
    {
        if (i >= n || j < 0)
            break;
        // ll temp1;
        // if (a[j] != 0)
        // {
        //     temp1 = d / a[j];
        //     temp1++;
        // }
        // else
        //     continue;
        ll temp1 = d / a[j];
        temp1++;

        if ((j - i + 1) >= temp1)
            ans++;
        j--;
        i += temp1 - 1;

        if (i >= n)
            break;
    }
    cout << ans << '\n';
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

    // int t;
    // cin >> t;
    // while (t--)
    // {
    // ll n;
    // cin>>n;
    // vector<ll> a(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>a[i];
    // }
    // solve(n,a);

    solve();
    // }

    return 0;
}
