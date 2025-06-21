#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int longest = 0;
    int i = 1, j = 0;
    // i will keep moving, and when then condition is met j also moves
    while (i < n)
    {
        if (abs(a[i] - a[i - 1]) > k)
        {
            j = i;
        }
        longest = max(longest, i - j + 1);
        i++;
    }

    int ans = n - longest;
    if(n==1) ans=0;
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
        solve();
    }

    return 0;
}
