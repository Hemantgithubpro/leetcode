#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m;
    cin >> n >> m;

    string out;
    out.reserve(2 * (n + m) - 1);

    if (m == 0)
        for (ll i = 0; i < 2 * n - 1; i++)
            out.push_back('<');
    else if (n == 0)
    {
        if (m == 1)
        {
            out.push_back('>');
        }
        else
        {
            out.push_back('>');
            for (ll i = 0; i < m - 1; i++)
            {
                out.push_back('=');
                out.push_back('>');
            }
        }
    }
    else
    {
        for (ll i = 0; i < 2 * n; i++)
            out.push_back('<');
        for (ll i = 0; i < 2 * m - 1; i++)
        {
            out.push_back((i % 2 == 0) ? '>' : '<');
        }
    }

    cout << out << '\n';
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
