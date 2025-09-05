#include <bits/stdc++.h>
using namespace std;

int makeTheIntegerZero(int num1, int num2)
{
    vector<long long> v(61);
    for (int i = 0; i <= 60; i++)
    {
        long long temp = pow(2, i);
        temp += num2;
        if (temp >= LLONG_MAX)
            // v[i] = LLONG_MAX;
            v[i] = 0;
    }
    if (num1 < num2)
        return -1;
}

int main()
{
}