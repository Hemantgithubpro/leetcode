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
    ll a;
    cin >> n >> a;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    const ll MINB = 0;
    const ll MAXB = 2000000000LL;

    vector<pair<ll, int>> events;
    events.reserve(2 * n);

    for (ll vi : v) {
        if (vi == a) continue; // impossible to win this marble

        ll L, R;
        if (vi < a) {
            // integers b with |vi - b| < |vi - a| -> [2*vi - a + 1, a - 1]
            L = 2 * vi - a + 1;
            R = a - 1;
        } else {
            // vi > a -> [a + 1, 2*vi - a - 1]
            L = a + 1;
            R = 2 * vi - a - 1;
        }

        if (R < MINB || L > MAXB) continue;
        L = max(L, MINB);
        R = min(R, MAXB);
        if (L > R) continue;

        events.emplace_back(L, +1);
        events.emplace_back(min(R + 1, MAXB + 1), -1); // end marker (exclusive)
    }

    if (events.empty()) {
        cout << 0 << '\n';
        return;
    }

    sort(events.begin(), events.end());

    ll curr = 0, best = -1, ans_b = 0;
    size_t i = 0;
    while (i < events.size()) {
        ll x = events[i].first;
        ll delta = 0;
        while (i < events.size() && events[i].first == x) {
            delta += events[i].second;
            ++i;
        }
        curr += delta;

        ll next_x = (i < events.size() ? events[i].first : (MAXB + 1));
        ll segL = max(x, MINB);
        ll segR = min(next_x - 1, MAXB);
        if (segL <= segR && curr > best) {
            best = curr;
            ans_b = segL; // any b in [segL, segR] works
        }
    }

    cout << ans_b << '\n';
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