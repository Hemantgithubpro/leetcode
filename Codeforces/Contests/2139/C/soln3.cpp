#include <bits/stdc++.h>
#define ll long long
typedef unsigned long long ull;

using namespace std;

void solve()
{
    int k;
    ull x;
    cin >> k >> x;
    ull T = 1ULL << (k + 1);
    ull base = T / 2;
    vector<int> ops;
    ull cur = x;
    while (cur != base)
    {
        if (cur < base)
        {
            ops.push_back(1);
            cur = cur * 2;
        }
        else
        {
            ops.push_back(2);
            cur = cur * 2 - T;
        }
    }
    reverse(ops.begin(), ops.end());
    cout << ops.size() << endl;
    if (!ops.empty())
    {
        for (size_t i = 0; i < ops.size(); i++)
        {
            if (i > 0)
                cout << " ";
            cout << ops[i];
        }
        cout << endl;
    }
}

// void solve(ll n, vector<ll>& a){

// }

int main()
{
#ifndef oNLINE_JUDGE
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
