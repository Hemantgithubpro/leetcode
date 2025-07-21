#include <bits/stdc++.h>
using namespace std;

int s(int temp)
{
    int ans = 0;
    while (temp > 0)
    {
        ans += temp % 10;
        temp /= 10;
    }
    return ans;
}
int p(int temp)
{
    int ans = 1;
    while (temp > 1)
    {
        ans *= temp % 10;
        temp /= 10;
    }
    return ans;
}

bool checkDivisibility(int n)
{
    int digisum = p(n);
    int digipro = s(n);
    long a = digisum + digipro;
    if ((long)n % a)
        return false;
    else
        return true;
}

int main()
{
    int n = 99;
    cout << checkDivisibility(n);
}