#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    string t = s;

    // keeping track of last occurence of '#'
    int idx = -1;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '#')
        {
            if (idx + 1 <= i - 1)
            {
                t[idx + 1] = 'o';
            }
            idx = i;
        }
    }

    if (idx + 1 <= n - 1)
    {
        t[idx + 1] = 'o';
    }

    cout << t;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}