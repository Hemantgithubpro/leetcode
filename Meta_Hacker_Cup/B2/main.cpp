#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 1e9 + 7;

// Function for modular exponentiation (a^b % mod)
ll power(ll base, ll exp)
{
    ll res = 1;
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

// Function to compute modular inverse using Fermat's Little Theorem
ll modInverse(ll n)
{
    return power(n, MOD - 2);
}

// Global pre-computed factorials up to the maximum possible exponent (approx 60)
vector<ll> fact;
const int MAX_EXPONENT = 65;

void precompute_factorials()
{
    fact.resize(MAX_EXPONENT);
    fact[0] = 1;
    for (int i = 1; i < MAX_EXPONENT; ++i)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

// Function to calculate W(F, N) for a factor F and number of terms N
// F is represented by its prime factorization {prime: exponent}
ll count_factor_ways(const map<ll, int> &factors, ll N)
{
    ll ways = 1;
    ll N_minus_1 = (N - 1) % MOD; // Use (N-1) mod M for addition/multiplication

    for (auto const &[p, e] : factors)
    {
        ll exponent = e;

        // Calculate C(exponent + N - 1, exponent) mod M
        // C(n, k) = n! / (k! * (n-k)!)
        // In our case: C(e + N - 1, e)
        // Since e is small, we calculate the numerator as a product:
        // (e + N - 1) * (e + N - 2) * ... * (N)

        ll numerator = 1;
        for (int i = 0; i < exponent; ++i)
        {
            // (N + exponent - 1 - i)
            ll term = (N_minus_1 + exponent - i) % MOD;
            numerator = (numerator * term) % MOD;
        }

        ll denominator_inv = modInverse(fact[exponent]);

        ll combinations = (numerator * denominator_inv) % MOD;
        ways = (ways * combinations) % MOD;
    }
    return ways;
}

// Function to get prime factorization of B
map<ll, int> prime_factorization(ll B)
{
    map<ll, int> factors;
    ll tempB = B;

    for (ll i = 2; i * i <= tempB; ++i)
    {
        if (tempB % i == 0)
        {
            int count = 0;
            while (tempB % i == 0)
            {
                tempB /= i;
                count++;
            }
            factors[i] = count;
        }
    }
    if (tempB > 1)
    {
        factors[tempB] = 1;
    }
    return factors;
}

void solve(int case_num)
{
    ll N, A, B;
    if (!(cin >> N >> A >> B))
        return;

    // --- 1. Prime Factorization of B ---
    map<ll, int> B_factors = prime_factorization(B);

    // --- 2. Iterate over all factors F1 of B ---
    ll total_sequences = 0;

    // Recursive function to generate all factors of B
    function<void(ll, map<ll, int>, ll, ll)> generate_factors =
        [&](ll current_factor, map<ll, int> current_F1_factors, ll B_remaining, ll current_prime_idx)
    {
        // Base case: If B_remaining is 1, we have a complete factor F1.
        if (current_prime_idx == B_factors.size() + 1)
        {
            if (current_factor > A)
                return; // Constraint F1 <= A

            // F1 is the product of the first N multipliers.
            // F2 = B / F1 is the product of the last N multipliers.
            ll F1 = current_factor;
            ll F2 = B / F1;

            // --- Find factors for F2 ---
            map<ll, int> F2_factors;
            for (auto const &[p, e] : B_factors)
            {
                int e1 = current_F1_factors[p];
                F2_factors[p] = e - e1;
            }

            // --- Calculate W(F1, N) * W(F2, N) ---
            ll ways1 = count_factor_ways(current_F1_factors, N);
            ll ways2 = count_factor_ways(F2_factors, N);

            ll current_ways = (ways1 * ways2) % MOD;
            total_sequences = (total_sequences + current_ways) % MOD;
            return;
        }

        // --- Recursive Step ---
        auto it = B_factors.begin();
        advance(it, current_prime_idx - 1);
        ll p = it->first;
        int e = it->second;

        // Try all powers of p (from 0 to e) for F1
        ll p_power = 1;
        for (int e_i = 0; e_i <= e; ++e_i)
        {
            if (current_factor > A / p_power && p_power > 1)
            {
                // Optimization: Avoid exceeding A early
                break;
            }

            if (current_factor * p_power > A)
            {
                break;
            }

            map<ll, int> next_F1_factors = current_F1_factors;
            if (e_i > 0)
                next_F1_factors[p] = e_i;

            generate_factors(current_factor * p_power, next_F1_factors, B_remaining / p_power, current_prime_idx + 1);

            p_power *= p;
        }
    };

    // Prepare initial call
    map<ll, int> empty_factors;
    generate_factors(1, empty_factors, B, 1);

    cout << "Case #" << case_num << ": " << total_sequences << "\n";
}

// void solve(ll n, vector<ll>& a){

// }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int i = 1;
    while (t--)
    {
        // ll n;
        // cin>>n;
        // vector<ll> a(n);
        // for (int i = 0; i < n; i++)
        // {
        //     cin>>a[i];
        // }
        // solve(n,a);

        solve(i++);
    }

    return 0;
}
