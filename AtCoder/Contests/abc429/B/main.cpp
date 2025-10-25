#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (sum - a[i] == m)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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
