#include <bits/stdc++.h>
using namespace std;

bool ifallfull(vector<char> &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '.')
            return false;
    }
    return true;
}

bool ifallempty(vector<char> &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '#')
            return false;
    }
    return true;
}

void solve(int n, vector<char> &s)
{
    // .=empty, #=full
    int ans = 0;
    if (ifallfull(s))
    {
        cout << 0 << endl;
        return;
    }

    // i've to find if there are continous '.' in quantity of 3 or more, then that portion will only need 2.
    for (int i = 0; i < n;)
    {
        int j = i;
        while (j < n && s[j] == '.') {
            j++;
        }
        int count = j - i;
        if (count >= 3) ans += 2;
        else ans += count;
        i = j + 1;
    }
    

    cout << ans << endl;
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
        int n;
        cin >> n;
        vector<char> s(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }

        solve(n, s);
    }

    return 0;
}
