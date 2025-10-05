#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    int maxSatisfaction = 0;

    for (int L = 0; L <= 100; ++L)
    {
        int sumTastiness = 0;
        for (int i = 0; i < n; ++i)
        {
            if (b[i] <= L && a[i] > 0)
            {
                sumTastiness += a[i];
            }
        }
        int satisfaction = sumTastiness - L;
        maxSatisfaction = max(maxSatisfaction, satisfaction);
    }

    cout << maxSatisfaction << '\n';
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
