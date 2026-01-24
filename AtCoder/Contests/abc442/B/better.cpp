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
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
const int N = 1e7 + 10;
using ll = long long;
using namespace std;

bool checkstatus(int vol, bool isplaying)
{
    bool ans = true;
    if (vol < 3)
        return false;
    if (isplaying == false)
        return false;
    return true;
}

void solve()
{
    int q;
    cin >> q;
    vec(a, q);
    cin(a, q);
    int vol = 0;
    bool isplaying = false;
    floop(q)
    {
        if (a[i] == 1)
        {
            vol++;
            if (checkstatus(vol, isplaying))
                yes;
            else
                no;
        }
        else if (a[i] == 2)
        {
            if (vol > 0)
                vol--;
            if (checkstatus(vol, isplaying))
                yes;
            else
                no;
        }
        else
        {
            isplaying = !isplaying;
            if (checkstatus(vol, isplaying))
                yes;
            else
                no;
        }
    }
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    // {
    solve();
}
// }