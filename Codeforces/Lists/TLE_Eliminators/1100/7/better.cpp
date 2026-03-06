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

bool check(int mid, vector<int> &a, int x)
{
    ll units = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < mid)
            units += (mid - a[i]);
    }
    return units <= x;
}
void solve()
{
    int n, x;
    cin >> n >> x;
    vec(a, n);
    cin(a, n);

    // asort(a);

    // 3 1 2 4 6 2 5
    // 1 2 2 3 4 5 6

    // ll sum=0;
    // floop(n){
    //     sum+=a[i];
    // }
    // ll rest = n*a[n-1] - sum;

    // ll ans=0;

    // if(x>=rest){
    //     ans=a[n-1];
    //     x-=rest;
    //     ans+=x/n;
    // }
    // else{

    // }

    ll ans = 0;
    int l = 0;
    int r = INT_MAX;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid, a, x))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans << endl;
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