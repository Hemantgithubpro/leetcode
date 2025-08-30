#include <bits/stdc++.h>
using namespace std;

int min_operations(int n, const string &s)
{
    int l = 2 * n;
    string pattern1, pattern2;
    for (int i = 0; i < l; i++)
    {
        pattern1 += (i % 2 == 0 ? 'A' : 'B');
        pattern2 += (i % 2 == 0 ? 'B' : 'A');
    }

    vector<int> a_pos, b_pos;
    int ops1 = 0, ops2 = 0;

    // For pattern ABAB...
    for (int i = 0; i < l; i++)
    {
        if (pattern1[i] != s[i])
        {
            if (pattern1[i] == 'A')
                a_pos.push_back(i);
            else
                b_pos.push_back(i);
        }
    }
    for (int i = 0; i < a_pos.size(); i++)
        ops1 += abs(a_pos[i] - b_pos[i]);
    

    a_pos.clear();
    b_pos.clear();

    // For pattern BABA...
    for (int i = 0; i < l; i++)
    {
        if (pattern2[i] != s[i])
        {
            if (pattern2[i] == 'A')
                a_pos.push_back(i);
            else
                b_pos.push_back(i);
        }
    }
    for (int i = 0; i < a_pos.size(); i++)
        ops2 += abs(a_pos[i] - b_pos[i]);

    return min(ops1, ops2);
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    cout << min_operations(n, s);
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

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
