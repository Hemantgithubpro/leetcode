#include <bits/stdc++.h>
using namespace std;

bool isgood(string &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        int temp = a[i] - '0';
        if (i % 2 == 0)
        {
            if (temp % 2 == 1)
                return false;
        }
        else
        {
            int t = temp;
            if (t == 0 || t == 1 || t == 4 || t == 6 || t == 8 || t == 9)
                return false;
        }
    }
    return true;
}

int countGoodNumbers(long long n)
{
    const long long MOD = pow(10, 9) + 7;
    long long ans = 1;


    // string of length pow(10,n-1) to pow(10,n)-1
    // ex. n=6, "100000" to "999999", but how do i check for every number in between. i got it, permutation and combination will be used
    // like count how many odd places, then combination of prime values(4) there, and how many even places, then even(5) there.
    // n=7, 0123456
    long long oddplaces = n / 2;
    long long evenplaces = n - oddplaces;
    // while (evenplaces--)
    // {
    //     ans %= MOD;
    //     ans *= 5;
    // }
    // while (oddplaces--)
    // {
    //     ans %= MOD;
    //     ans *= 4;
    // }

    // vector of power of 5
    




    return ans % MOD;
}

int main()
{
    long long n = 806166225460393;
    cout << countGoodNumbers(n);
    return 0;
}