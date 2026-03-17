#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define asort(a) sort(a.begin(), a.end())
#define vsort(a) sort(a.rbegin(), a.rend())
#define toLow transform(s.begin(), s.end(), s.begin(), ::tolower)
#define floop(n) for (int i = 0; i < n; i++)
#define floop2(n) for (int j = 0; j < n; j++)
#define aint(a) a.begin(), a.end()
#define vec(a, n) vector<int> a(n)
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
vector<int> removeDuplicates(vector<int> &a)
{
    unordered_set<int> seen;
    vector<int> b;

    for (int x : a)
    {
        if (seen.find(x) == seen.end())
        {
            b.push_back(x);
            seen.insert(x);
        }
    }
    return b;
}

void solve()
{
    int n;
    cin >> n;
    vec(a, n);
    cin(a, n);
    if (n < 2)
    {
        cout << 0 << endl;
        return;
    }
    vector<int> b;
    bool isincreasing = true;
    vector<int> rd = removeDuplicates(a);
    int result = rd.size();

    b.push_back(rd[0]);
    for (int i = 0; i < rd.size() - 1; i++)
    {
        if (rd[i + 1] > rd[i])
        {
            // increasing, now check if prev was increasing or decreasing
            if (!isincreasing)
            {
                b.push_back(rd[i + 1]);
                isincreasing = true;
            }
        }
        else
        {
            // decreasing
            if (isincreasing)
            {
                b.push_back(rd[i + 1]);
                isincreasing = false;
            }
        }
        // cout << i << ":" << result << ' ';
    }
    result = b.size();

    cout << result << endl;
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
