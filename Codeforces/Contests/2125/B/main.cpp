#include <bits/stdc++.h>
#define ll long long

using namespace std;

long long custom_gcd(long long a, long long b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve()
{
    // input here only
    ll a, b, k;
    cin >> a >> b >> k;
    // ll common_divisor = custom_gcd(a, b);
    ll common_divisor = __gcd(a, b);

    if ((a / common_divisor <= k) && (b / common_divisor <= k))
    {
        cout << 1 << "\n";
    }
    else
    {
        cout << 2 << "\n";
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
