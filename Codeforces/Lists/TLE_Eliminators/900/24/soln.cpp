#include <bits/stdc++.h>
using namespace std;
// #define __gcd(a, b) gcd(a, b)
typedef long long ll;

void solve()
{
    ll a, b;
    cin >> a >> b;

    // ig the difference is the maximum ans to achieve
    // gcd(a,b) = gcd(a-b,b)
    ll ans = abs(a - b);
    ll c = min(a, b);
    ll count = 0;
    if (ans > 0)
        count = min(c % ans, ans - (c % ans));
    cout << ans << " " << count << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        // input
        solve();
    }

    return 0;
}
