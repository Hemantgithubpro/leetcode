#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<string> grid;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        grid.push_back(s);
    }

    int size = N + 2;
    vector<vector<char>> big_grid(size, vector<char>(size, '#'));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            big_grid[i + 1][j + 1] = grid[i][j];
        }
    }

    vector<vector<int>> dist(size, vector<int>(size, -1));
    queue<pair<int, int>> q;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (big_grid[i][j] == '#')
            {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < size && ny >= 0 && ny < size)
            {
                if (dist[nx][ny] == -1)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    vector<tuple<int, int, int>> cells;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == '.')
            {
                int d_val = dist[i + 1][j + 1];
                cells.push_back(make_tuple(d_val, i, j));
            }
        }
    }

    sort(cells.begin(), cells.end());

    for (auto &cell : cells)
    {
        cout << get<1>(cell) << " " << get<2>(cell) << "\n";
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

    solve();

    return 0;
}
