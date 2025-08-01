#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int n)
{
    vector<vector<int>> result;
    for (int i = 0; i < n; i++)
    {
        result[i] = vector<int>(i + 1, 1);

        for (int j = 0; j < i; j++)
        {
            result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
        }
    }
    return result;
}

// but below is the dp approach which i wanted
vector<vector<int>> generate(int numRows)
{
    if (numRows == 0)
        return {};
    if (numRows == 1)
        return {{1}};

    vector<vector<int>> prevRows = generate(numRows - 1);
    vector<int> newRow(numRows, 1);

    for (int i = 1; i < numRows - 1; i++)
    {
        newRow[i] = prevRows.back()[i - 1] + prevRows.back()[i];
    }

    prevRows.push_back(newRow);
    return prevRows;
}
int main()
{
}