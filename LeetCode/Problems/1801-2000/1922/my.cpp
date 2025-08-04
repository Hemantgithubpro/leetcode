#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
long long power(long long base, long long exp)
{
    long long res = 1;
    base %= MOD;

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }

    return res;
}
int countGoodNumbers(long long n)
{
    if (n % 2)
    {
        long long t = n - 1;
        return (power(20, t / 2) * 5) % MOD;
        // long long ans=(pow(20,t/2)*5)%MOD;
        // ans*=5;
        // return ans%MOD;
    }
    else
    {
        return power(20, n / 2) % MOD;
        // long long ans=pow(20,n/2)%MOD;
        // return ans%MOD;
    }
}

int main()
{
}