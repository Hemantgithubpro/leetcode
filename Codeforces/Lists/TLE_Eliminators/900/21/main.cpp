#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
    long long n;
    cin >> n;
    if (n % 25 == 0)
    {
        cout << 0 << endl;
        return;
    }
    string s = to_string(n);
    unordered_map<char, int> o;
    unordered_set<char> t;
    unordered_set<char> f;
    unordered_set<char> se;

    for (int i = s.size() - 1; i >= 0; i--)
    { // 00 or 25 or 50 or 75
        if (s[i] == '0')
            o[s[i]]++;
        else if (s[i] == '2')
            t.insert(s[i]);
        else if (s[i] == '5')
            f.insert(s[i]);
        else if (s[i] == '7')
            se.insert(s[i]);

        if (t.size() > 0 && f.size() > 0 && s[i] == '2')
        {
            cout << s.size() - i - 2 << endl;
            return;
        }
        if (f.size() > 0 && o['0'] > 0 && s[i] == '5')
        {
            cout << s.size() - i - 2 << endl;
            return;
        }
        if (se.size() > 0 && f.size() > 0 && s[i] == '7')
        {
            cout << s.size() - i - 2 << endl;
            return;
        }
        if (o['0'] > 1)
        {
            cout << s.size() - i - 2 << endl;
            return;
        }
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
