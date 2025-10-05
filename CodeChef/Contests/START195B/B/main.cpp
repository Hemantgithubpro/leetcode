#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int max_len = 0;

    int zeros = 0;
    int ones = 0;
    for (char c : s)
    {
        if (c == '0')
        {
            zeros++;
        }
        else
        {
            ones++;
        }
    }
    max_len = max(zeros, ones);

    int len0 = 0;
    int len01 = 0;
    for (char c : s)
    {
        if (c == '0')
        {
            len0++;
        }
        else
        {
            len01 = max(len01 + 1, len0 + 1);
        }
    }
    max_len = max(max_len, max(len0, len01));

    int len1 = 0;
    int len10 = 0;
    for (char c : s)
    {
        if (c == '1')
        {
            len1++;
        }
        else
        {
            len10 = max(len10 + 1, len1 + 1);
        }
    }
    max_len = max(max_len, max(len1, len10));

    cout << n - max_len << endl;
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
