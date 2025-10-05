#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    long long n, l, r, k;
    cin >> n >> l >> r >> k;

    if (n % 2 == 1)
    {
        cout << l << '\n';
    }
    else
    {
        if (n == 2)
        {
            cout << -1 << '\n';
        }
        else
        {
            long long x = l;
            bool found = false;
            while (x <= r)
            {
                if ((x & l) == 0)
                {
                    if ((x | l) <= r)
                    {
                        found = true;
                        break;
                    }
                }
                x++;
            }
            if (!found)
            {
                cout << -1 << '\n';
            }
            else
            {
                if (k == 3)
                {
                    cout << x << '\n';
                }
                else if (k == n)
                {
                    cout << (x ^ l) << '\n';
                }
                else
                {
                    cout << l << '\n';
                }
            }
        }
    }
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
