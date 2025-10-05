#include <bits/stdc++.h>
using namespace std;

bool isAP(long long a, long long b, long long c)
{
    // difference to be => a+c=2*b
    if (b - a == c - b)
        return true;
    return false;
}

// this is my own solution and its giving TLE on test 4
void solve()
{
    // code
    long long a, b, c;
    cin >> a >> b >> c;
    if (isAP(a, b, c))
    {
        cout << "YES" << endl;
        return;
    }
    // // if there is only one '1'
    // if ((a == 1 && b != 1 && c != 1) ||
    //     (b == 1 && a != 1 && c != 1) ||
    //     (c == 1 && a != 1 && b != 1))
    // {
    //     cout << "YES" << endl;
    //     return;
    // }

    // i've two choices if we've to make the sequence increasing or decreasing
    // first try to increase the edges, a or c, first c.
    long long temp = 2 * b - a;
    long long tempc = c;
    for (long long i = 1; tempc * i <= temp; i++)
    {
        tempc = tempc * i;
        if (tempc == temp)
        {
            cout << "YES" << endl;
            return;
        }
        tempc = c;
    }

    // try increasing a
    temp = 2 * b - c;
    long long tempa = a;
    for (long long i = 1; tempa * i <= temp; i++)
    {
        tempa = tempa * i;
        if (tempa == temp)
        {
            cout << "YES" << endl;
            return;
        }
        tempa = a;
    }

    // try increasing b
    if ((a + c) % 2 == 0)
    {
        temp = (a + c) / 2;
        long long tempb = b;
        for (long long i = 1; tempb * i <= temp; i++)
        {
            tempb = tempb * i;
            if (tempb == temp)
            {
                cout << "YES" << endl;
                return;
            }
            tempb = b;
        }
    }

    cout << "NO" << endl;
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
    long long t;
    cin >> t;
    while (t--)
    {
        // input
        solve();
    }

    return 0;
}
