#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<char> allow(n, 0);
    for (int c = 1; c <= n - 2; c++)
        allow[c] = 1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            for (int d = -1; d <= 1; d++)
            {
                int c = i + d;
                if (1 <= c && c <= n - 2)
                    allow[c] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            bool covered = false;
            for (int d = -1; d <= 1; d++)
            {
                int c = i + d;
                if (1 <= c && c <= n - 2 && allow[c])
                {
                    covered = true;
                    break;
                }
            }
            if (!covered)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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
