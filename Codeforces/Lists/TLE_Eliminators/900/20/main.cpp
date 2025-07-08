#include <bits/stdc++.h>
using namespace std;
// after a long time, did some question on my own.


int ab(string s)
{
    int count = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == 'a' && s[i + 1] == 'b')
            count++;
    }
    return count;
}
int ba(string s)
{
    int count = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == 'b' && s[i + 1] == 'a')
            count++;
    }
    return count;
}

void solve()
{
    string s;
    cin >> s;
    if (ab(s) == ba(s))
        cout << s << endl;
    else
    {
        if (ab(s) > ba(s))
        { // to decrease one ab
            // either change front or last
            if (s[0] == 'a')
                s[0] = 'b';
            else if (s[s.size() - 1] == 'b')
                s[s.size() - 1] = 'a';
        }
        else
        { // to decrease one ba
            if (s[0] == 'b')
                s[0] = 'a';
            else if (s[s.size() - 1] == 'a')
                s[s.size() - 1] = 'b';
        }
        cout << s << endl;
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
