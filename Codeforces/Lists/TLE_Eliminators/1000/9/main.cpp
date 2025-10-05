#include <bits/stdc++.h>
#define ll long long

using namespace std;

// will give tle
ll lcm(ll a, ll b)
{
    return (a / __gcd(a, b)) * b;
}

void solve()
{
    // input here only
    ll n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << n / 2 << " " << n / 2 << endl;
        return;
    }
    else
    {
        // for (ll i = n / 2; i > 0; i--)
        // {
        //     ll a = i;
        //     ll b = n - a;
        //     if (b % a == 0) // (n-a)%a => n%a==0, a should be the factor of n
        //     {
        //         cout << a << " " << b << endl;
        //         return;
        //     }
        // }
        ll ansa;
        for (ll a = 2; a * a <= n; a++)
        {
            if (n % a == 0)
            {
                ansa = n / a;
                cout << ansa << " " << n - ansa << endl;
                return;
            }
        }
        cout << 1 << " " << n - 1 << endl;
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
