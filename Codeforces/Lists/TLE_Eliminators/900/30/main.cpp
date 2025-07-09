#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
    string s;
    cin >> s;
    // noof1 and noof0
    int noof1 = 0, noof0 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            noof0++;
        else
            noof1++;
    }

    int pairs = min(noof0, noof1);
    if (pairs % 2 == 0)
        cout << "NET" << endl;
    else
        cout << "DA" << endl;
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
