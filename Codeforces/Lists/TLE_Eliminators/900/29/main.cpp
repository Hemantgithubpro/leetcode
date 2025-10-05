#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // brute force is possible from seeing the constraints
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    unordered_set<int> pi, pj, pk;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (a[i] < a[j] && a[j] > a[k])
                {
                    cout << "YES" << endl;
                    cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
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
