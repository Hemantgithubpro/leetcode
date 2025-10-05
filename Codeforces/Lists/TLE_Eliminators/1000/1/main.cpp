#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve()
{
    string s;
    cin >> s;
    ll initialone = 0, initialzero = 0;
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            initialone++;
        else
            initialzero++;
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
        solve();
    }

    return 0;
}
