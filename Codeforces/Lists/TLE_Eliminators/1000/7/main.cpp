#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        um[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        um[b[i]]++;
    }
    int ans = 0;
    // sort(a.begin(),a.end());
    // sort(b.begin(),b.end());
    for (auto it = um.begin(); it != um.end(); it++)
    {
        ans = max(ans, it->second);
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
