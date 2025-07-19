#include <bits/stdc++.h>
using namespace std;

// algo to count no. of primes in range [l,r]
int countprimes(int l, int r)
{
    int count = 0;
    for (int num = max(2, l); num <= r; ++num)
    {
        bool is_prime = true;
        for (int i = 2; i * i <= num; ++i)
        {
            if (num % i == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            ++count;
    }
    return count;
}

// write another function to find primes
vector<int> sieve_primes(int n)
{
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = i * 2; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

int nonSpecialCount(int l, int r)
{
    // Calculate the limit up to which we need to find prime numbers
    int lim = (int)(sqrt(r));

    // Create a boolean array to mark primes up to lim using Sieve of Eratosthenes
    vector<bool> v(lim + 1, true);
    v[0] = v[1] = false; // 0 and 1 are not prime numbers

    // Sieve of Eratosthenes to mark non-prime numbers
    for (int i = 2; i * i <= lim; i++)
    {
        if (v[i])
        {
            for (int j = i * i; j <= lim; j += i)
            {
                v[j] = false;
            }
        }
    }

    // Count special numbers in the range [l, r]
    int cnt = 0;
    for (int i = 2; i <= lim; i++)
    {
        if (v[i])
        {
            int square = i * i;
            if (square >= l && square <= r)
            {
                cnt++;
            }
        }
    }

    // Total numbers in the range [l, r]
    int totalCount = r - l + 1;

    // Calculate non-special numbers
    return totalCount - cnt;
}

int main()
{
}