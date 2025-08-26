#include <bits/stdc++.h>
using namespace std;

// my own solution worked till 814/816 testcases, and wrong answer on 815th test case
double diag(int a, int b) { return sqrt(a * a + b * b); }
int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
{
    pair<int, int> maxi = {0, 0};
    double ma = 0;
    for (int i = 0; i < dimensions.size(); i++)
    {
        double temp = diag(dimensions[i][0], dimensions[i][1]);
        ma = max(ma, temp);
        if (ma == temp)
            maxi = {dimensions[i][0], dimensions[i][1]};
    }
    return maxi.first * maxi.second;
}

int main()
{
}