#include <bits/stdc++.h>
using namespace std;

// recursion+memoization
int dfs(vector<vector<int>> &fruits, int row, int col, int moves, vector<vector<int>> &memo, vector<pair<int, int>> &dirs)
{
    int n = fruits.size();
    if (row == n - 1 && col == n - 1)
        return moves == 0 ? 0 : INT_MAX; // if moves are none left return 0, else this path is not possible
    if (moves == 0 || row == col)
        return INT_MAX;
    if (memo[row][col] != -1)
        return memo[row][col];

    int max_fruits = -1;
    for (auto [dir1, dir2] : dirs)
    {
        int newrow = row + dir1;
        int newcol = col + dir2;
        if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < n)
        { // within boundaries
            int val = dfs(fruits, newrow, newcol, moves - 1, memo, dirs);
            if (val != INT_MAX)
                max_fruits = max(max_fruits, val);
        }
    }
    return memo[row][col] = (max_fruits < 0 ? INT_MAX : fruits[row][col] + max_fruits);
}

int maxCollectedFruits(vector<vector<int>> &fruits)
{
    int ans = 0;
    int n = fruits.size();

    // Case A (0,0): only diagnal
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        a += fruits[i][i];
    }

    // Case B (0,n-1): from top right
    // movement: down/ down-left/ down-right
    vector<pair<int, int>> move = {{1, -1}, {1, 0}, {1, 1}};
    vector<vector<int>> memo(n, vector<int>(n, -1));
    int b = dfs(fruits, 0, n - 1, n - 1, memo, move);

    // Case C (n-1,0): from bottom left
    // movement: right/ up-right/ down-right
    vector<pair<int, int>> move2 = {{-1, 1}, {0, 1}, {1, 1}};
    vector<vector<int>> memo2(n, vector<int>(n, -1)); // Separate memo table
    int c = dfs(fruits, n - 1, 0, n - 1, memo2, move2);

    return a + b + c;
}

int main()
{
    vector<vector<int>> fruits = {
        {1, 2, 3, 4},
        {5, 6, 8, 7},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    cout << maxCollectedFruits(fruits);
};