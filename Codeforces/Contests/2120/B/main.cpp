#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool reachesCorner(long long x, long long y, int dx, int dy, long long s)
{

    if (dx == -1)
        x = s - x;
    if (dy == -1)
        y = s - y;

    long long g = gcd(x, s);
    long long h = gcd(y, s);
    long long lcm_gh = (g * h) / gcd(g, h);

    long long period_x = s / g;
    long long period_y = s / h;
    long long period = (period_x * period_y) / gcd(period_x, period_y);

    return (x * period_y) % s == (y * period_x) % s;
}

int main()
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
        int n;
        long long s;
        cin >> n >> s;

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int dx, dy;
            long long x, y;
            cin >> dx >> dy >> x >> y;

            if (reachesCorner(x, y, dx, dy, s))
            {
                count++;
            }
        }

        cout << count << "\n";
    }

    return 0;
}