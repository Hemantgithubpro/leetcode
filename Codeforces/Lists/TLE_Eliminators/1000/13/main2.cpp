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
    int max_val = a[0] + x;
    int min_val = a[0] - x;
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        int curr_min = a[i] - x;
        int curr_max = a[i] + x;

        // Check if current range overlaps with previous range
        if (curr_max < min_val || curr_min > max_val)
        {
            // No overlap, need a new segment
            count++;
            min_val = curr_min;
            max_val = curr_max;
        }
        else
        {
            // Update the intersection of ranges
            min_val = max(min_val, curr_min);
            max_val = min(max_val, curr_max);
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
