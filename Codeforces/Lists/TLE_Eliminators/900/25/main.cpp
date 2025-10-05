#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
    int n, m, i, j;
    cin >> n >> m >> i >> j;
    // answer is (1,1) and (n,m)
    cout << 1 << " " << 1 << " " << n << " " << m << endl;
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
    while (t--)
    {
        // input
        solve();
    }

    return 0;
}
