#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string a;
    cin >> a;

    int max_len = 0;
    for (char ch : {'0', '1'})
    {
        int cnt = 0, l = 0;
        for (int r = 0; r < n; ++r)
        {
            cnt += (a[r] == ch);
            while (cnt > 1)
                cnt -= (a[l++] == ch);
            max_len = max(max_len, r - l + 1);
        }
    }
    for (int i = 0; i + 3 < n; ++i)
    {
        if ((a.substr(i, 4) == "0101") || (a.substr(i, 4) == "1010"))
            max_len = max(max_len, 4);
    }
    cout << max_len << endl;
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
