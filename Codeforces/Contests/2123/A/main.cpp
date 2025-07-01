#include <bits/stdc++.h>
#define ll long long

using namespace std;

string solve(int n)
{
    if (n % 4 == 0)
    {
        return "Bob";
    }
    else
    {
        return "alice";
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

    int t;
    cin >> t;
    while (t--)
    {
        // ll n;
        // cin>>n;
        // vector<ll> a(n);
        // for (int i = 0; i < n; i++)
        // {
        //     cin>>a[i];
        // }
        // solve(n,a);
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }

    return 0;
}
