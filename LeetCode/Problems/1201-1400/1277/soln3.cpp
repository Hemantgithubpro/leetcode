#include <bits/stdc++.h>
using namespace std;
// bottom up approach
// finding soln of smaller sub problems then combining them to find larger sub problems

int countSquares(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> memo(m, vector<int>(n, 0));
    int result = 0;

    // memo[i][j]= total square submatrices having 1s ending at cell [i][j]
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
                memo[i][j] = matrix[i][j];
            else if (matrix[i][j] == 1)
                memo[i][j] = 1 + min({memo[i - 1][j], memo[i - 1][j - 1], memo[i][j - 1]});
            result += memo[i][j];
        }
    }
    return result;
}