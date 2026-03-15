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

bool consider(vector<int> &a, int ans)
{
    int l = 0;
    int r = a.size() - 1;
    while (l <= r)
    {
        if (a[l] != a[r])
        {
            if (a[l] == ans)
                l++;
            else if (a[r] == ans)
                r--;
            else
                return false;
        }
        else
        {
            l++;
            r--;
        }
    }

    return true;
}

void solve()
{
    int n;
    cin >> n;
    vec(a, n);
    cin(a, n);

    int l = 0, r = n - 1;
    bool flag = true;
    int ans = 0;

    while (l <= r)
    {
        if (a[l] != a[r])
        {
            // either l++, or r--, and save the int of a[l] or a[r]

            // a[l]
            int left=a[l];
            if(!consider(a,left)){
                no;
                return;
            }
            // 1 2 2 3 1
            // a[r]
            int right= a[r];
            if(!consider(a,right)){
                no;
                return;
            }
        }
        l++;
        r--;
    }
    yes;
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