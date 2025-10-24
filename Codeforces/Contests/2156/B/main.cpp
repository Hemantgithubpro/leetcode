#include <bits/stdc++.h>
#define ll long long

using namespace std;

// soln is correct but tle
int get(int num, string &s)
{
    int ans = 0;
    int n = s.size();
    int i = 0;
    while (num)
    {
        if (s[i] == 'A')
            num--;
        else
            num /= 2;
        ans++;
        i = (i + 1) % n;
    }
    return ans;
}

void solve()
{
    // input here only
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> que(q);
    for (int i = 0; i < q; i++)
    {
        cin >> que[i];
        cout << get(que[i], s) << endl;
    }
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
