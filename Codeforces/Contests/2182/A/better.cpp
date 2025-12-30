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
    int n;
    cin >> n;
    string s;
    cin >> s;

    const string target = "2026";
    int ansA = INT_MAX;
    for (int i = 0; i + 4 <= n; ++i)
    {
        int diff = 0;
        for (int j = 0; j < 4; ++j)
            diff += (s[i + j] != target[j]);
        ansA = min(ansA, diff);
    }

    const string pattern = "2025";
    vector<int> pi(4, 0);
    for (int i = 1; i < 4; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 && pattern[i] != pattern[j])
            j = pi[j - 1];
        if (pattern[i] == pattern[j])
            ++j;
        pi[i] = j;
    }

    auto next_state = [&](int state, char ch) -> int
    {
        while (state > 0 && ch != pattern[state])
            state = pi[state - 1];
        if (ch == pattern[state])
            ++state;
        return state;
    };

    const vector<char> digits = {'0', '2', '5', '6'};
    const int INF = 1e9;
    vector<int> dp(4, INF), ndp(4, INF);
    dp[0] = 0;
    for (int idx = 0; idx < n; ++idx)
    {
        fill(ndp.begin(), ndp.end(), INF);
        for (int st = 0; st < 4; ++st)
        {
            if (dp[st] == INF)
                continue;
            for (char ch : digits)
            {
                int ns = next_state(st, ch);
                if (ns == 4)
                    continue;
                int cost = dp[st] + (ch != s[idx]);
                ndp[ns] = min(ndp[ns], cost);
            }
        }
        dp.swap(ndp);
    }
    int ansB = *min_element(dp.begin(), dp.end());

    cout << min(ansA, ansB) << endl;
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