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
#define vec(a, n) vector<ll> a(n)
#define cin(a, n)               \
    for (int i = 0; i < n; i++) \
    cin >> a[i]
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const int N = 1e7 + 10;
using ll = long long;
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    ll q;
    cin >> q;
    vec(a, n);
    cin(a, n);
    vec(x, q);
    cin(x, q);

    // for (int i = 0; i < q; i++)
    // {
    //     ll e=pow(2,x[i]);
    //     for(int j=0; j<n; j++){
    //         if(a[j]%e==0) a[j]+=pow(2,x[i]-1);
    //     }
    // }

    // asort(x);
    // if (q == 0)
    // {
    //     for (int i = 0; i < n; i++)
    //         cout << a[i] << ' ';
    //     cout << endl;
    //     return;
    // }

    // vec(psum, q);
    // psum[0] = (1LL << (x[0] - 1));
    // for (int i = 1; i < q; i++)
    // {
    //     psum[i] = psum[i - 1] + (1LL << (x[i] - 1));
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     // if (!isPowerOfTwo(a[i]))
    //     //     continue;
    //     if (a[i] & 1)
    //         continue;
    //     for (int j = q - 1; j >= 0; j--)
    //     {
    //         ll e = (1LL << x[j]);
    //         if (a[i] % e == 0)
    //         {
    //             // a[i] += pow(2, x[j] - 1);
    //             a[i] += psum[j];
    //             break;
    //         }
    //     }
    // }

    ll prev = 31; // Initialize 'prev' to 31, which is greater than any possible x[i]

    for (int i = 0; i < q; i++)
    { // Loop through each query
        if (x[i] >= prev)
            continue; // Skip if current x[i] is not less than 'prev'

        ll val = pow(2, x[i]); // Calculate 2^x[i]

        for (int j = 0; j < n; j++)
        { // Loop through each element of array 'a'
            if (a[j] % val == 0)
            {                      // Check if a[j] is divisible by 2^x[i]
                a[j] += (val / 2); // Add (2^x[i] / 2) to a[j]
            }
        }

        prev = x[i]; // Update 'prev' to current x[i]
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}
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