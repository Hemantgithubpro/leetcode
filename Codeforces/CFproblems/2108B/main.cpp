#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // problem has explicity said array to have positive numbers and 0 is not a positive number
    int n, x;
    cin >> n >> x;
    if (n == 1 && x == 0)
    {
        cout << -1 << endl;
        return;
    }
    if (n % 2 == 1)
    {
        if (x != 0)
        {

            vector<int> a(n - 1, 1);
            int ans = x;
            for (int i = 0; i < n - 1; i++)
            {
                ans = ans ^ 1;
            }
            int sum = ans + (n - 1);
            cout << sum;
        }
        else
        {
            cout << -1;
        }
    }
    else
    {
        if (x == 0)
            cout << n;
        else
        {
            cout << -1;
        }
    }

    cout << endl;
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
