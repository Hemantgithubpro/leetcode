#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    unordered_set<char> usleft, usright;
    vector<int> preleft(n), preright(n);

    for (int i = 0; i < n; i++)
    {
        usleft.insert(s[i]);
        preleft[i] = usleft.size();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        usright.insert(s[i]);
        // preright.push_back(usright.size());
        preright[i] = usright.size();
    }

    // now putting dividers at n-1 positions
    for (int i = 0; i < n - 1; i++)
    {
        int temp = preleft[i] + preright[i + 1];
        ans = max(ans, temp);
    }
    cout << ans << endl;
    
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
