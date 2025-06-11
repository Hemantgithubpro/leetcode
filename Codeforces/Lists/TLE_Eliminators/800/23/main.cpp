#include <bits/stdc++.h>
using namespace std;

bool reachable(int a, int b, int c, int d)
{
    if (d >= b)
    {
        int temp1 = b - a;
        int temp2 = d - c;
        if (temp2 >= temp1)
        {
            return true;
        }
    }
    return false;
}

void solve(int a, int b, int c, int d)
{
    if (reachable(a, b, c, d))
    {
        int ans = 0;
        int yup = d - b;
        int xleft = a-c;
        ans += yup;
        xleft += yup;
        ans += xleft;
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        // a,b to c,d via (x+1,y+1) or (x-1,y)
        solve(a, b, c, d);
    }

    return 0;
}
