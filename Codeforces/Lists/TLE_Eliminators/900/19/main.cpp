#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    // i know this approach will give tle, but just give it a try.
    ll x, n; // initial position, no. of jumps
    cin >> x >> n;

    for (ll i = 1; i <= n; i++)
    {
        if (x % 2 == 0) // even=> jump left
        {
            x -= i;
        }
        else // odd=> jump right
        {
            x += i;
        }
    }
    cout << x << endl;
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
