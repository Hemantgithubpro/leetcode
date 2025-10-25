#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        if (i < m)
            cout << "OK";
        else
            cout << "Too Many Requests";
        cout << endl;
    }
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
