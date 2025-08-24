#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<int> scores(n, 0);
    for (int j = 0; j < m; ++j)
    {
        int count0 = 0;
        int count1 = 0;

        for (int i = 0; i < n; ++i)
        {
            if (s[i][j] == '0')
            {
                count0++;
            }
            else
            {
                count1++;
            }
        }

        if (count0 == 0 || count1 == 0)
        {
            for (int i = 0; i < n; ++i)
            {
                scores[i]++;
            }
        }
        else if (count0 < count1)
        {
            for (int i = 0; i < n; ++i)
            {
                if (s[i][j] == '0')
                {
                    scores[i]++;
                }
            }
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                if (s[i][j] == '1')
                {
                    scores[i]++;
                }
            }
        }
    }

    int max_score = 0;
    for (int i = 0; i < n; ++i)
    {
        if (scores[i] > max_score)
        {
            max_score = scores[i];
        }
    }

    vector<int> winners;
    for (int i = 0; i < n; ++i)
    {
        if (scores[i] == max_score)
        {
            winners.push_back(i + 1);
        }
    }

    for (int i = 0; i < winners.size(); ++i)
    {
        cout << winners[i] << (i == winners.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main()
{
// #ifndef OnLInE_JUDGE
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
