#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve()
{
    string s;
    cin >> s;
    if (s.size() == 1)
    {
        cout << 1 << endl;
        return;
    }
    ll initialone = 0, initialzero = 0;
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            initialone++;
        else
            initialzero++;
    }
    string rearranged = "";
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == '1' && initialzero > 0)
        {
            rearranged += '0';
            initialzero--;
        }
        else if (s[i] == '0' && initialone > 0)
        {
            rearranged += '1';
            initialone--;
        }
        else
        {
            if (initialzero > 0)
            {
                rearranged += '0';
                initialzero--;
            }
            else
            {
                rearranged += '1';
                initialone--;
            }
        }
    }
    // cout << rearranged << endl;
    int count = 0;
    for (ll i = 0; i < s.size(); i++)
    {
        if (rearranged[i] == s[i])
        {
            count = s.size() - i;
            cout << count << endl;
            // cout << i << endl;
            return;
        }
    }
    cout << 0 << endl;
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
