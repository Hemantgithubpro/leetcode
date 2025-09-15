#include <bits/stdc++.h>
#define ll long long

using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<char> present(n + 1, false);
    int zeros = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        if (x == 0)
            zeros++;
        else if (x >= 1 && x <= n)
            present[x] = true;
    }

    int pre = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == i)
            pre++;
        else
            break;
    }

    int suf = 0;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == i)
            suf++;
        else
            break;
    }

    int ans = n - pre - suf;

    if (zeros == 0)
    {
        cout << max(0, ans) << endl;
        return;
    }

    if (zeros == 1)
    {
        int missing = 0, zpos = 0;
        for (int v = 1; v <= n; v++)
            if (!present[v])
            {
                missing = v;
                break;
            }
        for (int i = 1; i <= n; i++)
            if (a[i] == 0)
            {
                zpos = i;
                break;
            }
        if (zpos == missing)
            ans--;
    }

    cout << max(0, ans) << endl;
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
