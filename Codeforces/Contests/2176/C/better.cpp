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
bool ok(int k, int teven, int even, int odd)
{
    if (teven < 0)
        return false;
    ll waste = k - (teven + 1);
    if (waste < 0)
        return false;
    int re = even - teven;
    int ro = odd - 1;
    ll cap = re + 2LL * (ro / 2);
    if (waste > cap)
        return false;
    if ((waste & 1) && re == 0)
        return false;
    return true;
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> odd, even;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x & 1)
            odd.push_back(x);
        else
            even.push_back(x);
    }
    if (odd.empty())
    {
        for (int k = 1; k <= n; k++)
            cout << 0 << ' ';
        cout << endl;
        return;
    }
    sort(even.rbegin(), even.rend());
    ll best = *max_element(odd.begin(), odd.end());
    vector<ll> pref(even.size() + 1, 0);
    for (int i = 0; i < even.size(); i++)
        pref[i + 1] = pref[i] + even[i];

    int te = even.size(), to = odd.size();
    int ueven = 0;
    for (int k = 1; k <= n; k++)
    {
        int maxa = min(k - 1, te);
        if (ueven > maxa)
            ueven = maxa;

        while (ueven < maxa && ok(k, ueven + 1, te, to))
            ueven++;
        while (ueven >= 0 && !ok(k, ueven, te, to))
            ueven--;

        ll ans;
        if (ueven >= 0)
            ans = best + pref[ueven];
        else
            ans = 0;

        cout << ans << ' ';
    }
    cout << endl;
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