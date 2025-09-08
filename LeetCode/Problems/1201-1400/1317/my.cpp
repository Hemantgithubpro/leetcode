#include <bits/stdc++.h>
using namespace std;

bool isnonzero(int a)
{
    while (a > 0)
    {
        int temp = a % 10;
        if (temp == 0)
            return false;
        a /= 10;
    }
    return true;
}
vector<int> getNoZeroIntegers(int n)
{
    int a = n / 2;
    int b = n - a;
    while (a > 0 && b > 0)
    {
        if (isnonzero(a) && isnonzero(b))
            return {a, b};
        else
        {
            a++;
            b--;
        }
    }
    return {-1, -1};
}