#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long h, w, k;
    cin >> h >> w >> k;
    vector<long long> r(k), c(k);

    vector<vector<long long>> dist(h + 1, vector<long long>(w + 1, -1));
    vector<vector<vector<long long>>> neighbor_dists(h + 1, vector<vector<long long>>(w + 1));
    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq;

    for (long long i = 0; i < k; i++)
    {
        cin >> r[i] >> c[i];
        if (dist[r[i]][c[i]] == -1)
        {
            dist[r[i]][c[i]] = 0;
            pq.push({0, {r[i], c[i]}});
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        long long d = top.first;
        int cr = top.second.first;
        int cc = top.second.second;

        if (d > dist[cr][cc] && dist[cr][cc] != -1)
        {
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr >= 1 && nr <= h && nc >= 1 && nc <= w)
            {
                if (dist[nr][nc] != -1)
                    continue;

                neighbor_dists[nr][nc].push_back(d);
                if (neighbor_dists[nr][nc].size() >= 2)
                {
                    sort(neighbor_dists[nr][nc].begin(), neighbor_dists[nr][nc].end());
                    long long new_dist = 1 + neighbor_dists[nr][nc][1];
                    if (dist[nr][nc] == -1 || new_dist < dist[nr][nc])
                    {
                        dist[nr][nc] = new_dist;
                        pq.push({new_dist, {nr, nc}});
                    }
                }
            }
        }
    }

    long long total_moves = 0;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (dist[i][j] != -1)
            {
                total_moves += dist[i][j];
            }
        }
    }

    cout << total_moves << endl;

    return 0;
}