#include <bits/stdc++.h>
#define ll long long

using namespace std;

int longestCommonSubstring(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int result = 0; // Stores the maximum length found

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                result = max(result, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return result;
}

void solve()
{
    // input here only
    // longest common substring
    string s1, s2;
    cin >> s1 >> s2;

    int c=longestCommonSubstring(s1,s2);
    cout<<(s1.size()+s2.size()-2*c)<<endl;
    
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
