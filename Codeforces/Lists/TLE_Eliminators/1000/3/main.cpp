#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    ll n, p;
    cin >> n >> p;
    vector<pair<int, int>> data(n);
    // first: cost to tell each person , second: max people can be told
    for (int i = 0; i < n; i++)
    {
        cin >> data[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> data[i].first;
    }

    sort(data.begin(), data.end());
    ll mini = n * p;
    ll sum=0;
    for (int i = 0; i < n; i++)
    {
        
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
