#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> answers;
    for (int k = 1; k < 18; ++k)
    {
        ll p = 1;
        for (int i = 0; i < k; ++i)
            p *= 10;
        ll d = 1 + p;
        if (n < d)
            break;
        if (n % d == 0)
        {
            ll x = n / d;
            answers.push_back(x);
        }
    }
    if (answers.empty())
        cout << 0 << '\n';
    else
    {

        cout << answers.size() << endl;
        for (int i = answers.size() - 1; i >= 0; i--)
            cout << answers[i] << ' ';
        cout << '\n';
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
