#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool isDifficult(const string &s)
{
    for (int i = 0; i + 2 < s.size(); ++i)
    {
        if ((s[i] == 'F' && s[i + 1] == 'F' && s[i + 2] == 'T') || (s[i] == 'N' && s[i + 1] == 'T' && s[i + 2] == 'T'))
            return true;
    }
    return false;
}

void solve()
{
    // input here only
    string s;
    cin >> s;
    int n = s.size();
    string ans = "";

    sort(s.begin(), s.end());
    if (isDifficult(s))
    {
        reverse(s.begin(), s.end());
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
