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
    // a,b is a starting from 1 to n/
    if (n % 2 == 0)
    {
        cout << n / 2 << " " << n / 2 << endl;
    }
    else
    {
        vector<pair<ll, ll>> ab;
        pair<ll, ll> minimpair;
        ll mini = LLONG_MAX;
        for (int i = 1; i <= n / 2; i++)
        {
            ll a = i;
            ll b = n - a;
            ab.push_back({a, b});
            ll temp = lcm(a, b);
            mini = min(mini, temp);
            if (mini == temp)
            {
                minimpair = {a, b};
            }
        }
        cout << minimpair.first << " " << minimpair.second << endl;
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
