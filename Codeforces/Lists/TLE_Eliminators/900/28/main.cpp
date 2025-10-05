#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
    int n, k;
    cin >> n >> k;
    long long s = n * k;
    vector<int> a(s);
    for (long long i = 0; i < s; i++)
    {
        cin >> a[i];
    }

    long long pointer = s;
    long long sum = 0;
    while (k--)
    {
        pointer -= (n / 2 + 1);
        sum += a[pointer];
    }
    cout << sum << endl;
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
