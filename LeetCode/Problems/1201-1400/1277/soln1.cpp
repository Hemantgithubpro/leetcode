#include <bits/stdc++.h>
using namespace std;
// this solution is only recursion, which give tle, next soln2 include memoized version of the same soln below
int m, n;

int solve(int i, int j, vector<vector<int>> &matrix)
{
    if (i >= m || j >= n)
        return 0;
    if (matrix[i][j] == 0)
        return 0;
    int right = solve(i, j + 1, matrix);
    int diag = solve(i + 1, j + 1, matrix);
    int below = solve(i + 1, j, matrix);

    return 1 + min({right, diag, below});
}
int countSquares(vector<vector<int>> &matrix)
{
    m = matrix.size();
    n = matrix[0].size();

    int result = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1)
            {
                result += solve(i, j, matrix);
            }
        }
    }
    return result;
}

int main()
{
}