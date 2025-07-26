#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
    string s;
    cin >> s;
    int n = s.size();
    string t;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '#')
            t += '#';
        else
            t += '.';
    }

    // now replace '.' with 'o' with atleast '#' in b/w
    for (int i = 1; i < n; i++)
    {
        if (t[i] == '#')
        {
            if (t[i - 1] == '.')
                t[i - 1] = 'o';
        }
    }

    cout << t;
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
    // while (t--) {
    // input
    solve();
    // }

    return 0;
}
