#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// Function for modular exponentiation (to find modular inverse)
long long power(long long base, long long exp)
{
    long long res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Function to find modular inverse using Fermat's Little Theorem
long long modInverse(long long n)
{
    return power(n, MOD - 2);
}

int main()
{
// Fast I/O
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long c;
    cin >> n >> c;
    // Adjust c to be 0-indexed for vector access
    c--;

    vector<long long> a(n);
    long long initial_drawer_socks = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        initial_drawer_socks += a[i];
    }

    // The key insight is to consider the total "system" counts,
    // which include the sock being held. These counts are invariant.
    vector<long long> system_counts = a;
    system_counts[c]++;

    // The number of socks in the drawer when a draw occurs is constant.
    long long S = initial_drawer_socks;

    // The target system count corresponds to our initial color C.
    long long target_system_count = system_counts[c];

    // Sort the system counts in descending order to establish the DP order.
    vector<long long> sorted_system_counts = system_counts;
    sort(sorted_system_counts.rbegin(), sorted_system_counts.rend());

    // Calculate prefix sums of the sorted system counts.
    vector<long long> prefix_N(n);
    prefix_N[0] = sorted_system_counts[0];
    for (int i = 1; i < n; ++i)
    {
        prefix_N[i] = (prefix_N[i - 1] + sorted_system_counts[i]);
    }

    // Use a map to store the computed expected value E for each unique system count.
    map<long long, long long> count_to_e;

    // DP state: x_prev represents the sum of N_i * E_i for processed items.
    long long x_prev = 0;

    // Loop through the sorted counts to solve the recurrence.
    for (int i = 0; i < n; ++i)
    {
        long long current_N = sorted_system_counts[i];
        long long current_P_N = prefix_N[i];

        long long e;
        // If E is already computed for this count, reuse it.
        if (count_to_e.count(current_N))
        {
            e = count_to_e[current_N];
        }
        else
        {
            // The correct recurrence is: (P'_k - 1) * E'_k = S + X'_{k-1}
            long long denominator = current_P_N - 1;
            long long inv_denom = modInverse(denominator);

            long long term = (S + x_prev) % MOD;
            e = (term * inv_denom) % MOD;

            // Store the newly computed E value.
            count_to_e[current_N] = e;
        }

        // Update the DP state: X'_k = X'_{k-1} + N'_k * E'_k
        long long x_term = (current_N * e) % MOD;
        x_prev = (x_prev + x_term) % MOD;
    }

    // The answer is the expected value for the target sock's system count.
    cout << count_to_e[target_system_count] << endl;

    return 0;
}