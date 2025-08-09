#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n < 3)
    {
        cout << "No";
        return;
    }

    if (n >= 3 && s[n - 1] == 'a' && s[n - 2] == 'e' && s[n - 3] == 't')
        cout << "Yes";
    else
        cout << "No";
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
