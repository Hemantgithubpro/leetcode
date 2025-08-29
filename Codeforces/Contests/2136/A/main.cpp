#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool check(int score1, int score2)
{
    if (score1 > 2 * score2 + 2 || score2 > 2 * score1 + 2)
        return false;
    return true;
}
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool first = check(a, b);

    bool second = check(c - a, d - b);
    if (first && second)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
