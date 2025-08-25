#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<double> speed(n);
    speed[0] = 1;
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += a[i - 1];
        double y = sum;
        double x = a[i];
        double z = speed[i - 1];
        speed[i] = (double)(y / x) * z;
        cout << speed[i] << " ";
    }
    if (speed[n - 1] == 1)
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
