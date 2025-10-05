#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;

    unordered_map<char, int> um2;
    for (int i = 0; i < s2.size(); i++)
    {
        um2[s2[i]]++;
    }

    vector<int> pos; // storing the positions/indexes of first occurence from last.
    for (int i = 0; i < s2.size(); i++)
    {
        int temp = 0;
        int occur = um2[s2[i]];
        for (int j = s1.size() - 1; j >= 0; j--)
        {
            if (s1[j] == s2[i])
            {
                if (occur > 1)
                {
                    occur--;
                }
                else
                {
                    pos.push_back(j);
                    um2[s2[i]]--;
                    // continue;
                    break;
                }
            }
            else
                temp++;
        }
        if (temp >= s1.size())
        {
            cout << "NO" << endl;
            return;
        }
    }

    // now, i've the vector of indexes.
    for (int i = 0; i < pos.size() - 1; i++)
    {
        if (pos[i + 1] - pos[i] < 1)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

    // for (int i = 0; i < pos.size(); i++)
    // {
    //     cout << pos[i] << ' ';
    // }
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
