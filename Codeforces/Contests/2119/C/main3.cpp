#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    long long n, l, r, k;
    cin >> n >> l >> r >> k;
    
    // First, check if l=r and there's only one element
    if (n == 1) {
        if (l <= r) {
            cout << l << "\n";
        } else {
            cout << "-1\n";
        }
        return;
    }
    
    // For AND to equal XOR, each bit position must either have:
    // 1. All ones (contributes to AND and cancels in XOR if even count)
    // 2. Exactly one 1 (contributes to XOR only)
    
    // If n is even, AND=XOR is possible only if all elements are the same
    if (n % 2 == 0) {
        // For even n, all elements must be the same
        cout << (k <= n && l <= r ? l : -1) << "\n";
        return;
    }
    
    // For odd n, we can have all elements the same
    // The smallest such value would be l
    
    // Check if we have enough range to create a valid array
    if (r < 2*l) {
        // Not enough range to have different values
        cout << (k <= n ? l : -1) << "\n";
        return;
    }
    
    // For odd n ≥ 3, we can construct an array with first n-1 elements as l 
    // and the last element as 2*l (assuming 2*l ≤ r)
    // This satisfies AND=XOR because:
    // - For each bit in l, if it's 1, it appears odd number of times (n-1 times in first n-1 elements)
    // - For each bit in l, if it's 0, it appears n-1 times as 0 and once as possibly 1 in 2*l
    
    if (k < n) {
        cout << l << "\n";  // First n-1 elements are l
    } else if (k == n) {
        if (2*l <= r) {
            cout << 2*l << "\n";  // Last element is 2*l
        } else {
            // If 2*l > r, we can't construct a valid array
            cout << "-1\n";
        }
    } else {
        cout << "-1\n";  // k is out of bounds
    }
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

        solve();
    }

    return 0;
}
