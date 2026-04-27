#include <bits/stdc++.h>
using ll = long long;
#define mod 1000000007
#define pb push_back
#define asort(a) sort(a.begin(), a.end())
#define vsort(a) sort(a.rbegin(), a.rend())
#define toLow transform(s.begin(), s.end(), s.begin(), ::tolower)
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
using namespace std;

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

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    vec(a, n);
    cin(a, n);

    asort(a);
    int result = 0;
    // brute force
    // no. of beautiful pairs: n2
    // for(int i=0; i<n-1; i++){
    //     for(int j=i+1; j<n; j++){
    //         int sum=a[i]+a[j];
    //         int dif=a[j]-a[i];
    //         if(sum%x==0 && dif%y==0) result++;
    //     }
    // }

    // better approach
    // We need (a[i] + a[j]) % x == 0 and (a[j] - a[i]) % y == 0
    // This implies:
    // a[j] % x == (x - a[i] % x) % x
    // a[j] % y == a[i] % y
    map<pair<int, int>, ll> cnt;
    long long result2 = 0;
    for (int i = 0; i < n; i++)
    {
        int mod_x = a[i] % x;
        int mod_y = a[i] % y;
        int target_x = (x - mod_x) % x;

        result2 += cnt[{target_x, mod_y}];
        cnt[{mod_x, mod_y}]++;
    }

    cout << result2 << endl;
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
