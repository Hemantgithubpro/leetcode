#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    int n, r, b;
    cin >> n >> r >> b;
    // Distribute r 'R's into b+1 slots (before, between, and after b 'B's)
    int slots = b + 1;
    int base = r / slots;
    int extra = r % slots;
    string s = "";
    for (int i = 0; i < slots; i++)
    {
        int num_r = base + (i < extra ? 1 : 0);
        for (int j = 0; j < num_r; j++)
            s += "R";
        if (i < b)
            s += "B";
    }

    cout << s << endl;
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
