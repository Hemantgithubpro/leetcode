#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    ll n, p;
    cin >> n >> p;
    vector<pair<ll, ll>> v(n);
    vector<ll> a(n), b(n);

    for (int i = 0; i < n; i++) // n
        cin >> a[i];

    for (int i = 0; i < n; i++) // n
        cin >> b[i];

    for (int i = 0; i < n; i++) // n
        v[i] = {b[i], a[i]};

    sort(v.begin(), v.end()); // nlogn

    ll minimum_cost = p;
    ll already_shared = 1;

    for (auto it : v) // n
    {
        ll can_be_shared = it.second;
        ll sharing_cost = it.first;

        if (sharing_cost >= p)
            break;

        if (already_shared + can_be_shared > n)
        {
            minimum_cost += (n - already_shared) * sharing_cost;
            already_shared = n;
            break;
        }
        else
        {
            minimum_cost += can_be_shared * sharing_cost;
            already_shared += can_be_shared;
        }
    }

    minimum_cost += (n - already_shared) * p; // chief sharing
    cout << minimum_cost << endl;
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
