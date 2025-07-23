#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> perm(n);

    // iota assigns 1 to n
    iota(perm.begin(), perm.end(), 1);

    reverse(perm.begin(), perm.end());
    reverse(perm.end() - m, perm.end());

    for (int i = 0; i < n; i++)
    {
        cout << perm[i] << " ";
    }
    cout << '\n';
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
