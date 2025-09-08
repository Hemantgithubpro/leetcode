#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    ll k, x;
    cin >> k >> x;
    ll t = 1LL << (k + 1);
    ll base = t / 2;
    vector<int> rev;
    ll cur = x;
    while (cur != base)
    {
        if (cur < base)
        {
            rev.push_back(1);
            cur = cur * 2;
        }
        else
        {
            rev.push_back(2);
            cur = cur * 2 - t;
        }
    }
    reverse(rev.begin(), rev.end());
    cout << rev.size() << endl;
    for (int i = 0; i < rev.size(); i++)
    {
        cout << rev[i] << ' ';
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
