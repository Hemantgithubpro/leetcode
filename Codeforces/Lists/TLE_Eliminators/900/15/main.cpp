#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int mini = INT_MAX;
    int minindex = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < mini)
        {
            minindex = i;
            mini = a[i];
        }
    }
    if (mini <= 1)
    {
        cout << -1 << endl;
        return;
    }

    int count = 0;
    while (mini >= a[0])
    {
        a[0] = a[0] / 2;
        count++;
    }

    for (int i = 1; i < n || a[i] != mini; i++)
    {
        while (a[i] >= mini)
        {
            a[i] = a[i] / 2;
            count++;
        }
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
