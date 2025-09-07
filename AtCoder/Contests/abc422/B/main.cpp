#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for (int i = 0; i < h; i++)
        cin >> s[i];

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == '#')
            {
                int black = 0;

                for (int k = 0; k < 4; k++)
                {
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if (nr >= 0 && nr < h && nc >= 0 && nc < w)
                    {
                        if (s[nr][nc] == '#')
                            black++;
                    }
                }

                if (black != 2 && black != 4)
                {
                    cout << "No";
                    return;
                }
            }
        }
    }

    cout << "Yes";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--) {
    solve();
    // }

    return 0;
}
