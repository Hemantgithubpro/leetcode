#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans1 = 0;
    sort(a.begin(), a.end());
    for (int i = n - 1; i > 0; i--)
    {
        if (abs(a[i] - a[i - 1]) > k)
        {
            ans1 = i;
            break;
        }
    }

    int ans2 = 0;
    for (int i = 1; i < n; i++)
    {
        if (abs(a[i] - a[i - 1]) > k)
        {
            ans2 = n - i + 1;
            break;
        }
    }

    int ans = min(ans1, ans2);
    cout << ans << endl;
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
