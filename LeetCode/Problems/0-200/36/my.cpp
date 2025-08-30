#include <bits/stdc++.h>
using namespace std;

// not the most efficient, but did it in first try.
bool check(vector<vector<char>> &board, int row, int col)
{
    int top = board[row - 1][col] - '0';
    int topleft = board[row - 1][col - 1] - '0';
    int topright = board[row - 1][col + 1] - '0';
    int center = board[row][col] - '0';
    int centerleft = board[row][col - 1] - '0';
    int centerright = board[row][col + 1] - '0';
    int bottom = board[row + 1][col] - '0';
    int bottomleft = board[row + 1][col - 1] - '0';
    int bottomright = board[row + 1][col + 1] - '0';

    unordered_set<int> us;

    // Check for duplicates, ignoring empty cells
    if (board[row - 1][col] != '.')
    {
        if (us.count(top))
            return false;
        us.insert(top);
    }
    if (board[row - 1][col - 1] != '.')
    {
        if (us.count(topleft))
            return false;
        us.insert(topleft);
    }
    if (board[row - 1][col + 1] != '.')
    {
        if (us.count(topright))
            return false;
        us.insert(topright);
    }
    if (board[row][col] != '.')
    {
        if (us.count(center))
            return false;
        us.insert(center);
    }
    if (board[row][col - 1] != '.')
    {
        if (us.count(centerleft))
            return false;
        us.insert(centerleft);
    }
    if (board[row][col + 1] != '.')
    {
        if (us.count(centerright))
            return false;
        us.insert(centerright);
    }
    if (board[row + 1][col] != '.')
    {
        if (us.count(bottom))
            return false;
        us.insert(bottom);
    }
    if (board[row + 1][col - 1] != '.')
    {
        if (us.count(bottomleft))
            return false;
        us.insert(bottomleft);
    }
    if (board[row + 1][col + 1] != '.')
    {
        if (us.count(bottomright))
            return false;
        us.insert(bottomright);
    }

    return true;
}
bool isValidSudoku(vector<vector<char>> &board)
{
    // row wise check
    for (int i = 0; i < 9; i++)
    {
        unordered_set<int> a = {0};
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
                continue;
            char t = board[i][j];
            int temp = t - '0';
            if (a.count(temp))
                return false;
            else
                a.insert(temp);
        }
    }

    // column wise check
    for (int col = 0; col < 9; col++)
    {
        unordered_set<int> a = {0};
        for (int row = 0; row < 9; row++)
        {
            if (board[row][col] == '.')
                continue;
            char t = board[row][col];
            int temp = t - '0';
            if (a.count(temp))
                return false;
            else
                a.insert(temp);
        }
    }

    // 3x3 sub boxes check
    for (int i = 1; i < 9; i += 3)
    {
        for (int j = 1; j < 9; j += 3)
        {
            if (check(board, i, j) == false)
                return false;
        }
    }
    return true;
}

int main()
{
}