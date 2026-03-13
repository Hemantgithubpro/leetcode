#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define asort(a) sort(a.begin(), a.end())
#define vsort(a) sort(a.rbegin(), a.rend())
#define toLow transform(s.begin(), s.end(), s.begin(), ::tolower)
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
#define floop(n) for (int i = 0; i < n; i++)
#define floop2(n) for (int j = 0; j < n; j++)
#define all(a) a.begin(), a.end()
#define vec(a, n) vector<int> a(n)
#define cin(a, n)               \
    for (int i = 0; i < n; i++) \
    cin >> a[i]
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const int N = 1e7 + 10;
using ll = long long;
using namespace std;

ll modInverse(ll a, ll m) {
    ll res = 1, p = m-2;
    while(p){
        if(p&1) res = (res*a)%m;
        a = (a*a)%m;
        p >>= 1;
    }
    return res;
}

void solve() {
    ll n; cin >> n;

    ll inv6 = modInverse(6, mod);
    ll inv2 = (mod+1)/2; // modular inverse of 2

    ll sum1 = n%mod * (n+1)%mod %mod * (2*n+1)%mod %mod * inv6 %mod;
    ll sum2 = (n-1+mod)%mod * n%mod * (2*n-1+mod)%mod %mod * inv6 %mod;
    ll sum3 = (n-1+mod)%mod * n%mod %mod * inv2 %mod;

    ll ans = (sum1 + sum2 + sum3) %mod;
    ans = ans * 2022 %mod;

    cout << ans << endl;
}

// void solve()
// {
//     ll n;
//     cin >> n;

//     ll ans = 0;

//     for (ll i = 1; i <= n; i++)
//     {
//         ans %= mod;
//         ll term = (i % mod) * (i % mod) % mod;
//         ans += term;
//         ans %= mod;
//     }

//     for (ll i = 1; i < n; i++)
//     {
//         ans %= mod;
//         ll term = (i % mod) * ((i + 1) % mod) % mod;
//         ans += term;
//         ans %= mod;
//     }
//     ans *= 2022;
//     ans %= mod;

//     cout << ans << endl;
// }

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}