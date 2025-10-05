#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> &a)
{
    int noof2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 2)
            noof2++;
    }

    if (noof2 % 2 != 0)
        cout << -1 << endl;
    else if (noof2 == 0)
        cout << 1 << endl;
    else
    {
        // int pos = 0;
        // int countof2 = 0;
        // while (countof2 <= noof2 / 2)
        // {
        //     if (a[pos] == 2)
        //         countof2++;
        //     pos++;
        // }
        // cout << pos << endl;

        int countof2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (countof2 == noof2 / 2)
            {
                cout << i << endl;
                return;
            }
            if (a[i] == 2)
                countof2++;
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        solve(n, a);
    }

    return 0;
}
