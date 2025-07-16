#include <bits/stdc++.h>
using namespace std;

struct Block
{
    char ch;
    int len;
};

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<Block> rle;
    if (n > 0)
    {
        rle.push_back({s[0], 1});
        for (int i = 1; i < n; ++i)
        {
            if (s[i] == rle.back().ch)
            {
                rle.back().len++;
            }
            else
            {
                rle.push_back({s[i], 1});
            }
        }
    }

    int num_blocks = rle.size();
    if (num_blocks <= 2)
    {
        cout << n << endl;
        return;
    }

    int g0 = 0, g1 = 0;
    for (auto &block : rle)
    {
        if (block.ch == '0')
            g0++;
        else
            g1++;
    }

    if (g0 > g1)
    {
        int first_0_len = -1, last_0_len = -1;
        for (const auto &block : rle)
        {
            if (block.ch == '0')
            {
                if (first_0_len == -1)
                    first_0_len = block.len;
                last_0_len = block.len;
            }
        }
        if (g0 == 1)
        {
            cout << first_0_len << endl;
        }
        else
        {
            cout << first_0_len + last_0_len << endl;
        }
    }
    else if (g1 > g0)
    {
        int first_1_len = -1, last_1_len = -1;
        for (const auto &block : rle)
        {
            if (block.ch == '1')
            {
                if (first_1_len == -1)
                    first_1_len = block.len;
                last_1_len = block.len;
            }
        }
        if (g1 == 1)
        {
            cout << first_1_len << endl;
        }
        else
        {
            cout << first_1_len + last_1_len << endl;
        }
    }
    else
    {
        cout << rle.front().len + rle.back().len + 1 << endl;
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
