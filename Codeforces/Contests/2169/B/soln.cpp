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

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == '*' && s[i] == '*')
        {
            cout << -1 << endl;
            return;
        }
        if (s[i - 1] == '>' && s[i] == '<')
        {
            cout << -1 << endl;
            return;
        }
        if (s[i - 1] == '>' && s[i] == '*')
        {
            cout << -1 << endl;
            return;
        }
        if (s[i - 1] == '*' && s[i] == '<')
        {
            cout << -1 << endl;
            return;
        }
    }
    int largestleft = 0;
    int largestright = 0;
    int temp = 0;

    bool a = false;
    bool b = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '<')
        {
            temp++;
            largestleft = max(largestleft, temp);
        }
        else if (s[i] == '*' && largestleft > 0 && !a)
        {
            largestleft++;
            a = true;
            // temp = 0;
        }
        else
            temp = 0;
    }

    temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '>')
        {
            temp++;
            largestright = max(largestright, temp);
        }
        else if (s[i] == '*' && largestright == 0 && !b)
        {
            largestright++;
            b = true;
            // temp = 0;
        }
        else
            temp = 0;
    }
    int cnt = 0;
    cnt = max(largestleft, largestright);
    cout << cnt << endl;
    // i forgot '*>' or '<*'
    // it can be fixed if i know the ending position of largestleft or starting position of largestright
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