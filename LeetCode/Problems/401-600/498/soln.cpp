#include <bits/stdc++.h>
using namespace std;

// yt soln
vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();

    map<int, vector<int>> mp;

    vector<int> result;

    // fill the map using [i+j]
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            mp[i + j].push_back(mat[i][j]);

    bool flip = true;
    for (auto &it : mp)
    {
        if (flip)
            // it.second ko reverse kardo
            reverse(it.second.begin(), it.second.end());

        for (int &num : it.second)
            result.push_back(num);

        flip = !flip;
    }

    return result;
}

// most optimized
vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{

    int row = mat.size();
    int col = mat[0].size();
    vector<int> ans;

    int i = 0;
    int j = 0;

    bool upward = true;

    while (ans.size() < row * col)
    {
        ans.push_back(mat[i][j]);

        if (upward)
        {

            if (j == col - 1)
            {
                i++;
                upward = false;
            }
            else if (i == 0)
            {
                j++;
                upward = false;
            }
            else
            {
                i--;
                j++;
            }
        }
        else
        {

            if (i == row - 1)
            {
                j++;
                upward = true;
            }
            else if (j == 0)
            {
                i++;
                upward = true;
            }
            else
            {
                i++;
                j--;
            }
        }
    }

    return ans;
}

int main()
{
}