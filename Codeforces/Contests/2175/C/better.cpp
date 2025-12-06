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
    string s, t;
    cin >> s >> t;
    vector<int> cnt_s(26, 0), cnt_t(26, 0);
    for (char c : s)
        cnt_s[c - 'a']++;
    for (char c : t)
        cnt_t[c - 'a']++;
    bool possible = true;
    for (int i = 0; i < 26; i++)
    {
        if (cnt_s[i] > cnt_t[i])
        {
            possible = false;
            break;
        }
    }
    if (!possible)
    {
        cout << "Impossible" << endl;
        return;
    }
    vector<int> extra(26, 0);
    for (int i = 0; i < 26; i++)
    {
        extra[i] = cnt_t[i] - cnt_s[i];
    }
    string ans;
    int i = 0;
    int mini = 0;
    while (i < (int)s.size())
    {
        while (mini < 26 && extra[mini] == 0)
            mini++;
        if (mini == 26)
            break;
        char c = 'a' + mini;
        if (c < s[i])
        {
            ans += c;
            extra[mini]--;
        }
        else
        {
            ans += s[i];
            i++;
        }
    }
    ans += s.substr(i);
    for (int k = 0; k < 26; k++)
    {
        ans += string(extra[k], 'a' + k);
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