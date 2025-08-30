#include <bits/stdc++.h>
using namespace std;

long long f(long long x)
{
    string s = to_string(x);
    reverse(s.begin(), s.end());
    return stoll(s);
}

void solve()
{
    long long x, y;
    cin >> x >> y;

    vector<long long> a(11);
    a[1] = x;
    a[2] = y;

    for (int i = 3; i <= 10; i++)
    {
        a[i] = f(a[i - 1] + a[i - 2]);
    }

    cout << a[10] << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // your code goes here
    // int t;
    // cin >> t;
    // while (t--) {
    // input
    solve();
    // }

    return 0;
}
