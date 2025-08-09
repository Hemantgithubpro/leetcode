#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
    string s;
    cin >> s;

    double maxi = 0.0;
    int n = s.length();

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 2; j < n; ++j)
        {
            if (s[i] == 't' && s[j] == 't')
            {
                string sub = s.substr(i, j - i + 1);
                int t_count = 0;
                for (char c : sub)
                {
                    if (c == 't')
                    {
                        t_count++;
                    }
                }

                if (t_count >= 2)
                {
                    double fili = static_cast<double>(t_count - 2) / (sub.length() - 2);
                    if (fili > maxi)
                    {
                        maxi = fili;
                    }
                }
            }
        }
    }

    cout << fixed << setprecision(9) << maxi << endl;
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
