#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;

    unordered_map<char, int> um;
    for (int i = 0; i < s2.size(); i++)
    {
        um[s2[i]]++;
    }

    for (int i = s1.size() - 1; i >= 0; i--)
    {
        if (um[s1[i]] > 0)
        {
            um[s1[i]]--;
        }
        else
        {
            s1[i] = '_';
        }
    }

    string temp = "";
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != '_')
            temp += s1[i];
    }

    if (temp == s2)
        cout << "YES\n";
    else
        cout << "NO\n";
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
