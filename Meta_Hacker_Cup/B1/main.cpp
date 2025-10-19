#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(int i)
{
    ll n, a, b;
    cin >> n >> a >> b;

    ll f1 = a;
    while (f1 > 0 && (b % f1 != 0 || f1 > a))
        f1--;
    ll f2 = b / f1;

    cout << "Case #" << i << ":";

    for (int j = 0; j < n - 1; j++)
        cout << " 1";
    cout << " " << f1;

    for (int j = 0; j < n - 1; j++)
        cout << " 1";
    cout << " " << f2 << "\n";
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
    int i = 1;
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

        solve(i++);
    }

    return 0;
}
