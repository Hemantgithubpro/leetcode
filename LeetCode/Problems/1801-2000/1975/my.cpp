#include <bits/stdc++.h>
using namespace std;

long long maxMatrixSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int initialsum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            initialsum += matrix[i][j];
        }
    }

    // horizontal adjacent elements
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            int a = matrix[i][j];
            int b = matrix[i][j + 1];
            int c = a + b;
            int d = -1 * c;
            if (d > c)
            {
                matrix[i][j] *= -1;
                matrix[i][j + 1] *= -1;
            }
        }
    }

    // vertical adjacent elements
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a = matrix[i][j];
            int b = matrix[i + 1][j];
            int c = a + b;
            int d = -1 * c;
            if (d > c)
            {
                matrix[i][j] *= -1;
                matrix[i + 1][j] *= -1;
            }
        }
    }
    int newsum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            newsum += matrix[i][j];
        }
    }

    return max(newsum, initialsum);
}

int main()
{
}