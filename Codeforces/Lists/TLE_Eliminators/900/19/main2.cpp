#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll x, n; // initial position, no. of jumps
    cin >> x >> n;

    if (x % 2 == 0) // even=> jump left
    {
        // x -= i;
        if (n % 2 == 0)
        {
            x += n / 2;
        }
        else
        {
            // n--;
            x += n / 2;
            x -= n;
        }
    }
    else // odd=> jump right
    {
        // x += i;
        if (n % 2 == 0)
        {
            x -= n / 2;
        }
        else
        {
            // n--;
            x -= n / 2;
            x += n;
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
