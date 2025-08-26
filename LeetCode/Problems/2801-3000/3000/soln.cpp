#include <bits/stdc++.h>
using namespace std;

double diag(int a, int b) { return sqrt(a * a + b * b); }
int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
{
    double ma = 0;
    for (int i = 0; i < dimensions.size(); i++)
    {
        double temp = diag(dimensions[i][0], dimensions[i][1]);
        ma = max(ma, temp);
    }
    int area = 0;
    for (int i = 0; i < dimensions.size(); i++)
        if (abs(diag(dimensions[i][0], dimensions[i][1]) - ma) < 1e-9)
            area = max(area, dimensions[i][0] * dimensions[i][1]);
    return area;
}

int main()
{
}