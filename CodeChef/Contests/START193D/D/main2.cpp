#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> p(n);

    for (int i = 0; i < k - 1; i++)
    {
        p[i] = i + 1;
    }

    int curr = n;
    for (int i = k - 1; i < n; i++)
    {
        p[i] = curr;
        curr--;
    }

    for (int i = 0; i < n; i++)
    {
        // if (i == n - 1)
        //     cout << p[i];
        // else
        cout << p[i] << " ";
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