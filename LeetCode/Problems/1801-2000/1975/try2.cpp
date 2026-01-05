#include <bits/stdc++.h>
using namespace std;

long long maxMatrixSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // if there are odd no. of negatives, make the smallest one the negative
    // else take the sum of all of their modulus
    int mini = INT_MAX;
    int neg = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num = matrix[i][j];
            int temp = num;
            if (temp < 0)
                temp *= -1;
            if (temp < mini)
            {
                mini = temp;
            }
            if (num < 0)
                neg++;
            sum += temp;
        }
    }

    if (neg % 2)
        sum -= 2 * mini;
    return sum;
}

int main()
{
}