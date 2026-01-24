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

void solve() {
    int n;
    cin >> n;
    vector<string> g(n);
    floop(n) cin >> g[i];

    vector<vector<int>> cost(n, vector<int>(n + 1));
    for (int j = 0; j < n; j++) {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (g[i][j] == '.') cur++;
        }
        cost[j][0] = cur;
        for (int k = 0; k < n; k++) {
            if (g[k][j] == '.')
                cost[j][k + 1] = cost[j][k] - 1;
            else
                cost[j][k + 1] = cost[j][k] + 1;
        }
    }

    vector<ll> dp(n + 1);
    for (int k = 0; k <= n; k++) dp[k] = cost[0][k];

    for (int j = 1; j < n; j++) {
        vector<ll> suf(n + 2);
        suf[n + 1] = 1e18;
        for (int k = n; k >= 0; k--) suf[k] = min(dp[k], suf[k + 1]);
        for (int k = 0; k <= n; k++) dp[k] = cost[j][k] + suf[k];
    }

    ll ans = 1e18;
    for (int k = 0; k <= n; k++) ans = min(ans, dp[k]);
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
    solve();
}