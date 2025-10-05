#include <bits/stdc++.h>
using namespace std;

void dfs(int r, int c, const vector<vector<int>> &heights, vector<vector<bool>> &visited, int prevHeight)
{
    int rows = heights.size();
    int cols = heights.empty() ? 0 : heights[0].size();
    if (r < 0 || c < 0 || r >= rows || c >= cols)
        return;
    if (visited[r][c])
        return;
    if (heights[r][c] < prevHeight)
        return;
    visited[r][c] = true;
    dfs(r + 1, c, heights, visited, heights[r][c]);
    dfs(r - 1, c, heights, visited, heights[r][c]);
    dfs(r, c + 1, heights, visited, heights[r][c]);
    dfs(r, c - 1, heights, visited, heights[r][c]);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    if (heights.empty() || heights[0].empty())
        return {};
    int rows = heights.size();
    int cols = heights[0].size();
    vector<vector<bool>> pac(rows, vector<bool>(cols, false));
    vector<vector<bool>> atl(rows, vector<bool>(cols, false));

    for (int c = 0; c < cols; ++c)
    {
        dfs(0, c, heights, pac, heights[0][c]);
        dfs(rows - 1, c, heights, atl, heights[rows - 1][c]);
    }
    for (int r = 0; r < rows; ++r)
    {
        dfs(r, 0, heights, pac, heights[r][0]);
        dfs(r, cols - 1, heights, atl, heights[r][cols - 1]);
    }

    vector<vector<int>> result;
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            if (pac[r][c] && atl[r][c])
                result.push_back({r, c});
        }
    }
    return result;
}

int main()
{
}