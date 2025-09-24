#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n;
        cin >> n;
        vector<ll> a(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        
        vector<ll> ans(n + 1, 0);
        
        vector<ll> prefix(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; i++) {
            prefix[i + 1] = prefix[i] + a[i];
        }
        
        ans[n] = (prefix[2 * n] - prefix[n]) - (prefix[n] - prefix[0]);
        
        ans[1] = 0;
        for (int i = 0; i < n; i++) {
            ans[1] += a[2 * i + 1] - a[2 * i];
        }
        
        if (n > 2) {
            for (int k = 2; k < n; k++) {
                ans[k] = ans[1] + (ans[n] - ans[1]) * (k - 1) / (n - 1);
            }
        } else if (n == 2) {
            ans[2] = (a[2] + a[3]) - (a[0] + a[1]);
        }
        
        for (int k = 1; k <= n; k++) {
            cout << ans[k] << (k < n ? " " : "");
        }
        cout << "\n";
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
