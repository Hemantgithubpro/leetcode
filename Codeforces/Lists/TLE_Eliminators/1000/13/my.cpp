#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // range of v= a[i]-x to a[i]+x, take account of max and min range
    int maxi = a[0] + x;
    int mini = a[0] - x;
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        int currmin = a[i] - x;
        int currmax = a[i] + x;

        // if (a[i] >= mini - x && a[i] <= maxi + x)
        // {
        //     if (a[i] > a[i - 1])
        //         mini = a[i] - x;
        //     else if (a[i] < a[i - 1])
        //         maxi = a[i] + x;
        // }
        // else
        // {
        //     count++;
        //     maxi = a[i] + x;
        //     mini = a[i] - x;
        // }

        if (currmax < mini || currmin > maxi)
        {
            count++;
            mini = currmin;
            maxi = currmax;
        }
        else
        {
            mini = max(mini, currmin);
            maxi = min(maxi, currmax);
        }
    }
    cout << count << endl;
}

// void solve(ll n, vector<ll>& a){

// }

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

        solve();
    }

    return 0;
}
