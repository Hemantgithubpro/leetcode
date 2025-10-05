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

    bool answer = false;
    // i've two choices if we've to make the sequence increasing or decreasing
    // first try to increase the edges, a or c, first c.
    long long temp = 2 * b - a;
    long long tempc = c;
    if (temp / tempc > 0 && temp % tempc == 0)
        answer = true;

    // try increasing a
    temp = 2 * b - c;
    long long tempa = a;
    if (temp / tempa > 0 && temp % tempa == 0)
        answer = true;

    // try increasing b
    if ((a + c) % 2 == 0)
    {
        temp = (a + c) / 2;
        long long tempb = b;
        if (temp / tempb > 0 && temp % tempb == 0)
            answer = true;
    }

    if (answer)
        cout << "YES" << endl;
    else
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
