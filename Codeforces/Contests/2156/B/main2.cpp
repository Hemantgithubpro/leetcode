#include <bits/stdc++.h>
#define ll long long

using namespace std;
void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<ll> qs(q);
    for (int i = 0; i < q; i++)
        cin >> qs[i];

    bool allA = true;
    for (char c : s)
        if (c == 'B')
        {
            allA = false;
            break;
        }

    vector<ll> res;
    for (ll x : qs)
    {
        if (allA)
        {
            res.push_back(x);
            continue;
        }

        ll v = x, st = 0;
        int i = 0;
        while (v > 0)
        {
            st++;
            char m = s[i];
            if (m == 'A')
                v--;
            else
                v /= 2;
            if (i++ == n)
                i = 0;
        }
        res.push_back(st);
    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
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
