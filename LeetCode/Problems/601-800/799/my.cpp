#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    double t[101][101];
    double champagneTower(int poured, int query_row, int query_glass)
    {
        for (int i = 0; i < 101; i++)
        {
            for (int j = 0; j < 101; j++)
            {
                t[i][j] = -1;
            }
        }

        return min(1.00, solve(poured, query_row, query_glass));
    }
    double solve(int poured, int i, int j)
    {
        if (i < 0 || j < 0 || i < j)
            return 0.0;

        if (i == 0 && j == 0)
            return poured;

        if (t[i][j] != -1)
            return t[i][j]; 
        double left_up = (solve(poured, i - 1, j - 1) - 1) / 2;
        double right_up = (solve(poured, i - 1, j) - 1) / 2;

        if (left_up < 0)
            left_up = 0;
        if (right_up < 0)
            right_up = 0;

        return t[i][j]=left_up + right_up;
    }
};