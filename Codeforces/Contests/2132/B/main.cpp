#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    ll n;
    cin >> n;
    if (n >= 1000000000000000000 || n < 11)
    {
        cout << 0 << endl;
        return;
    }
    vector<ll> poss;
    ll temp = 1;
    ll div = pow(10, temp) + 1;
    while (n / div > 0)
    {
        if (n % div == 0)
            poss.push_back(n / div);
        temp++;
        div = pow(10, temp) + 1;
    }
    if (poss.size() == 0)
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
