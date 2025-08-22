#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    ll n;
    cin >> n;
    vector<ll> poss;
    ll div = 11;
    for (int k = 1; k <= 18; k++)
    {
        ll pow10 = 1;
        for (int i = 0; i < k; i++)
            pow10 *= 10;

        div = pow10 + 1;

        if (n % div == 0)
        {
            ll cur = n / div;
            if (cur % 10 != 0)
                poss.push_back(cur);
        }
    }
    if (poss.empty())
    {
        cout << 0 << endl;
        return;
    }
    cout << poss.size() << endl;
    for (int i = poss.size() - 1; i >= 0; i--)
    {
        cout << poss[i] << ' ';
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
