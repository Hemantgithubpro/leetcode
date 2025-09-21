#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }

    vector<int> f;
    for (auto &p : cnt)
        f.push_back(p.second);
    sort(f.begin(), f.end());

    int ans = 0;
    int m = f.size();
    for (int i = 0; i < m; ++i)
    {
        int cf = f[i];
        int k = m - i;
        int cur = cf * k;
        if (cur > ans)
            ans = cur;
    }

    cout << ans << endl;
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
