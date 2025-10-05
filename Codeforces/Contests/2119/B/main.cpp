#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    int n;
    cin >> n;
    long long px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    vector<int> a(n);
    long long total = 0;
    int max_a = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
        if (a[i] > max_a)
            max_a = a[i];
    }

    long long dx = qx - px;
    long long dy = qy - py;
    long long d_sq = dx * dx + dy * dy;
    long long L_val = max(0LL, 2LL * max_a - total);

    if (total * total < d_sq)
    {
        cout << "No\n";
    }
    else if (L_val * L_val > d_sq)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
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

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
