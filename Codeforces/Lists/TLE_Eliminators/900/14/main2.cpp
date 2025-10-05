#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    if (n % 2 != 0 || n < 4)
    {
        cout << -1 << endl;
        return;
    }
    long long mini = 0, maxi = 0;
    // 1 bus can have 4 wheels or 6 wheels

    // calculation for mini
    mini += n / 6;
    mini += (n % 6) / 4;
    if (n % 6 == 2)
        mini++;
    

    maxi += n / 4;
    // if (n % 4 == 2)
    // {
    //     cout << -1 << endl;
    //     return;
    // }

    cout << mini << " " << maxi << endl;
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
