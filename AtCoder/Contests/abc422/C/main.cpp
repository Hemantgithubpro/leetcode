#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    // code
    ll nA, nB, nC;
    cin >> nA >> nB >> nC;

    ll bound1 = min(nA, nC);
    
    ll total_letters = nA + nB + nC;
    ll bound2 = total_letters / 3;

    ll ans = min(bound1, bound2);
    cout << ans << endl;
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
        // input
        solve();
    }

    return 0;
}
