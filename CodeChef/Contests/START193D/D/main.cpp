#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
   int n,k; cin>>n>>k;
   vector<int> p;
    int m = n - k + 1;

    for (int i = m; i >= 1; --i) {
        p.push_back(i);
    }

    for (int i = m + 1; i <= n; ++i) {
        p.push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
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
