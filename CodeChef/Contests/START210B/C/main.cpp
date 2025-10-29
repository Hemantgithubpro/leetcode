#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // Count 1's without 0's after them and 0's without 1's before them
    // For each 1, we need a 0 before it in the same chain
    // For each 0, we need a 1 after it in the same chain
    
    // Method: track balance = count of 0's - count of 1's
    // If balance ever goes negative, we have 1's without enough 0's
    // These 1's must start new chains
    // At the end, remaining 0's must be in separate chains
    
    int balance = 0;
    int chains_needed = 0;
    
    // Forward pass: count 1's that appear before enough 0's
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            balance++;
        } else {
            balance--;
            if (balance < 0) {
                // We have more 1's than 0's so far
                // This 1 starts a new chain
                chains_needed++;
                balance = 0;  // reset as this 1 starts fresh chain
            }
        }
    }
    
    // Now add any remaining 0's (they need their own chains too)
    chains_needed += balance;
    
    cout << chains_needed << "\n";
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
