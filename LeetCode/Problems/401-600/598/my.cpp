#include <bits/stdc++.h>
using namespace std;

int maxCount(int m, int n, vector<vector<int>> &ops)
{
    // to find maximum, see the mat[0][0]
    int maxi = ops.size();
    if (ops.size() < 1)
        return m * n;
    // finding the smallest ops[i][0] and smallest ops[i][1]
    int a = INT_MAX, b = INT_MAX;
    for (int i = 0; i < ops.size(); i++)
    {
        a = min(ops[i][0], a);
        b = min(ops[i][1], b);
    }
    return a * b;
}

int main()
{
}