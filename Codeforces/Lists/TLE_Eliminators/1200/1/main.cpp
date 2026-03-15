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

vector<int> findMax3(vector<int> &arr)
{

    vector<pair<int, int>> tmp(arr.size());

    for (int i = 0; i < tmp.size(); i++)
    {

        tmp[i].first = arr[i];
        tmp[i].second = i;
    }

    sort(tmp.rbegin(), tmp.rend());

    vector<int> ans(3);

    for (int i = 0; i < 3; i++)
        ans[i] = tmp[i].second;

    return ans;
}

void solve()
{

    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);

    cin(a, n);
    cin(b, n);
    cin(c, n);

    vector<int> maxa = findMax3(a);

    vector<int> maxb = findMax3(b);
    vector<int> maxc = findMax3(c);

    int ans = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int x = maxa[i], y = maxb[j], z = maxc[k];

                if ((x == y) or (y == z) or (z == x))
                    continue;

                ans = max(ans, a[x] + b[y] + c[z]);
            }
        }
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
