#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    int t;
    cin >> t;
    int ans = 0;
    while (t--)
    {
        // input
        // solve();
        int a, b;
        cin >> a >> b;
        if (a < b)
            ans++;
    }
    cout << ans << endl;

    return 0;
}
