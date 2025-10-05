#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long L, R;
    std::cin >> L >> R;

    // If the range contains only one element, there is only one distinct value.
    if (L == R)
    {
        std::cout << 1 << std::endl;
        return 0;
    }

    long long start_range = L + 1;
    long long end_range = R;

    // This will store the total number of times the sequence value changes.
    long long changes = 0;

    // --- Step 1: Sieve for primes up to sqrt(R_max) ---
    // Constraints: R <= 10^14, so sqrt(R) <= 10^7.
    int limit = sqrt(end_range);

    std::vector<bool> is_prime_sieve(limit + 1, true);
    if (limit >= 0)
        is_prime_sieve[0] = false;
    if (limit >= 1)
        is_prime_sieve[1] = false;

    for (int p = 2; p * p <= limit; ++p)
    {
        if (is_prime_sieve[p])
        {
            for (int i = p * p; i <= limit; i += p)
                is_prime_sieve[i] = false;
        }
    }

    std::vector<int> primes_list;
    for (int p = 2; p <= limit; ++p)
    {
        if (is_prime_sieve[p])
        {
            primes_list.push_back(p);
        }
    }

    // --- Step 2: Count higher prime powers (p^k, k >= 2) ---
    for (int p : primes_list)
    {
        long long power = (long long)p * p; // Start with p^2
        while (power <= end_range)
        {
            if (power >= start_range)
            {
                changes++;
            }
            // Avoid overflow before the next multiplication
            if (end_range / p < power)
            {
                break;
            }
            power *= p;
        }
    }

    // --- Step 3: Count primes (p^1) using a segmented sieve ---
    long long range_size = end_range - start_range + 1;
    std::vector<bool> is_prime_segment(range_size, true);

    for (long long p : primes_list)
    {
        // Find the first multiple of p that is >= start_range
        long long start_multiple = (start_range + p - 1) / p * p;
        // Start marking from max(p*p, start_multiple) to avoid incorrectly
        // marking a prime p if the range starts at or before p.
        long long start_marking = std::max(start_multiple, (long long)p * p);

        for (long long j = start_marking; j <= end_range; j += p)
        {
            is_prime_segment[j - start_range] = false;
        }
    }

    // Count primes by iterating through the segment
    for (long long i = 0; i < range_size; ++i)
    {
        if (is_prime_segment[i])
        {
            long long current_num = start_range + i;
            // The segment sieve is only valid for numbers > limit.
            // For numbers <= limit, we must use the pre-computed sieve.
            if (current_num > limit)
            {
                changes++;
            }
            else
            {
                if (is_prime_sieve[current_num])
                {
                    changes++;
                }
            }
        }
    }

    // The total number of distinct values is 1 (for A_L) + number of changes.
    std::cout << 1 + changes << std::endl;

    return 0;
}