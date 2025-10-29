#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll A, B;
    cin >> A >> B;
    ll ans;
    if (A == B)
        ans = 2 * A - 1;
    else
        ans = A + B;
    cout << ans << '\n';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
