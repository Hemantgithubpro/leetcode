#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    // sum of multiples of 3 or 5.
    // 3,6,9, ...
    // plus 5,10,15,20 ...
    // minus 15,30,45 ...

    // 3+6+9... = 3(1+2+3...) = 3(n(n+1)/2)
    n--;
    long long ans = 0;
    long long three_count = n / 3;
    long long five_count = n / 5;
    long long fifteen_count = n / 15;

    long long three = three_count * (three_count + 1) / 2;
    long long five = five_count * (five_count + 1) / 2;
    long long fifteen = fifteen_count * (fifteen_count + 1) / 2;

    ans = (three*3) + (five*5) - (fifteen*15);
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

    // Your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        // input
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}
