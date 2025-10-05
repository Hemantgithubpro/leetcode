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
    // int t;
    // cin >> t;
    // while (t--)
    // {
        int n;
        cin >> n;
        vector<int> a(n);
        int m = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            m = min(m, abs(a[i]));
        }
        cout << m << endl;
    // }

    return 0;
}
