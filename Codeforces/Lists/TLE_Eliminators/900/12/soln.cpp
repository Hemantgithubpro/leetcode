#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // O(n^2)
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    int couldbe = 0;

    for (int i = 1; i < n; i++)
    {
        couldbe = max(couldbe, a[i] - a[0]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        couldbe = max(couldbe, a[n - 1] - a[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        couldbe = max(couldbe, a[i] - a[i + 1]);
    }

    cout << couldbe << endl;
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
