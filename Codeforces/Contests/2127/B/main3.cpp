#include <bits/stdc++.h>
#define ll long long

using namespace std;
void solve()
{
    int n;
    int x_one_based;
    cin >> n >> x_one_based;
    string s;
    cin >> s;

    int x = x_one_based - 1;

    bool wall_on_left = false;
    bool wall_on_right = false;

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '#')
        {
            if (i < x)
            {
                wall_on_left = true;
            }
            else if (i > x)
            {
                wall_on_right = true;
            }
        }
    }

    if (!wall_on_left || !wall_on_right)
    {
        cout << 1 << endl;
        return;
    }

    long long cost_L = x + 1;
    long long cost_R = n - x;

    cout << min(cost_L, cost_R) << endl;
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
