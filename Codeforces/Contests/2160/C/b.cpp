#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll reverse_bits(ll x)
{
    if (x == 0)
        return 0;
    ll rev = 0;
    while (x > 0)
    {
        rev = (rev << 1) | (x & 1);
        x >>= 1;
    }
    return rev;
}

int count_bits(ll x)
{
    int cnt = 0;
    while (x > 0)
    {
        cnt++;
        x >>= 1;
    }
    return cnt;
}

bool solve(ll n)
{
    if (n == 0)
        return true;

    // Try all possible bit lengths
    for (int len = 1; len <= 30; len++)
    {
        // For length len, first and last bit must be 1
        ll x = (1LL << (len - 1)) | 1; // Set first and last bit

        // Try all combinations for middle bits
        for (int mask = 0; mask < (1 << (len - 2)); mask++)
        {
            ll curr = x;
            // Set middle bits according to mask
            for (int i = 0; i < len - 2; i++)
            {
                if (mask & (1 << i))
                {
                    curr |= (1LL << (i + 1));
                }
            }

            ll rev = reverse_bits(curr);
            if ((curr ^ rev) == n)
            {
                return true;
            }
        }
    }
    return false;
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

        ll n;
        cin >> n;
        cout << (solve(n) ? "YES" : "NO") << "\n";
    }

    return 0;
}
