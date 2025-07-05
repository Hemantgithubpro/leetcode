#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    ll a, b;
    cin >> a >> b;
    
    // Mathematical analysis:
    
    // Case 1: A = 0 (no odd divisors)
    // Every positive integer has at least 1 as a divisor (which is odd)
    // So it's impossible to have A = 0
    if (a == 0) {
        cout << "No\n";
        return;
    }
    
    // Case 2: B = 0 (no even divisors)
    // This means N must be odd (since even divisors only exist for even numbers)
    // For an odd number, all its divisors are odd
    // So this is possible if A > 0
    if (b == 0) {
        if (a > 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        return;
    }
    
    // Case 3: A = 1 (exactly one odd divisor)
    // The only possible odd divisor is 1
    // This happens only for powers of 2 (2^k)
    // For 2^k, there are k even divisors (2, 4, 8, ..., 2^k)
    // So if A = 1, B must be positive for a valid number
    if (a == 1) {
        cout << (b > 0 ? "Yes\n" : "No\n");
        return;
    }
    
    // Case 4: General case
    // Let's analyze the structure of divisors:
    // For any N = 2^k × M where M is odd:
    // - The odd divisors are precisely the divisors of M
    // - The even divisors are obtained by multiplying each divisor of M by 2, 4, ..., 2^k
    // - So if M has d(M) divisors, then:
    //   * Number of odd divisors = d(M)
    //   * Number of even divisors = d(M) × k
    
    // For this problem, we have:
    // - Number of odd divisors = A = d(M)
    // - Number of even divisors = B = d(M) × k = A × k
    
    // So B must be divisible by A
    if (b % a == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

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
    while (t--)
    {
        solve();
    }

    return 0;
}
