#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    // two pointer approach
    unordered_map<int, int> uma, umb;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        uma[a[i]]++;
        umb[b[i]]++;
        // int temp = max(uma[a[i]], umb[b[i]]);
        // ans = max(ans, temp);
    }

    auto it1 = max_element(uma.begin(), uma.end());
    auto it2 = max_element(umb.begin(), umb.end());
    // cout << it1->first << endl;
    int i = 0, j = 0;
    
    // while (i < n || j < n)
    // {
    //     if (a[i] == b[i])
    //         i++;
    //     j++;
    // }

    // cout << ans << endl;
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
