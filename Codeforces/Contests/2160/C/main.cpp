#include <bits/stdc++.h>
#define ll long long

using namespace std;
bool is_palindrome(ll x, int m)
{
    ll rev = 0;
    ll tmp = x;
    for (int i = 0; i < m; i++)
    {
        rev = (rev << 1) | (tmp & 1);
        tmp >>= 1;
    }
    return rev == x;
}

void solve()
{
    // input here only
    ll n;
    cin >> n;
    if (n == 0)
    {
        cout << "YES" << endl;
        return;
    }
    int k = 0;
    ll n2 = n;
    while (n2)
    {
        k++;
        n2 >>= 1;
    }
    bool found = false;
    for (int L = k; L <= 2 * k; L++)
    {
        ll mask = (1LL << (L - k)) - 1;
        if (n & mask)
            continue;
        int M = 2 * k - L;
        if (M < 0)
            continue;
        ll high = n >> (L - k);
        if (!is_palindrome(high, M))
            continue;
        if (L % 2 == 1)
        {
            int shift = (L + 1) / 2 - 1;
            if ((n >> shift) & 1)
                continue;
        }
        found = true;
        break;
    }
    if (found)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
