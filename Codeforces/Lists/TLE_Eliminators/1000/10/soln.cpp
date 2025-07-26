#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    int n;
    cin >> n;
    char c;
    cin >> c;
    string s;
    cin >> s;
    if (c == 'g')
    {
        cout << 0 << '\n';
        return;
    }
    int maxi = 0;
    s += s;
    int idx = -1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == 'g')
            idx = i;
        if (s[i] == c)
        {
            maxi = max(maxi, idx - i);
        }
    }
    cout << maxi << '\n';
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
