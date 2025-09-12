#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    string s;
    cin >> s;
    int n = s.size();
    int total = 0;
    for (int i = 0; i < n; i++)
        total += s[i] - 'a' + 1;
    if (n % 2 == 0)
        cout << "Alice " << total;
    else
    {
        if (n == 1)
            cout << "Bob " << total;
        else
        {
            int first = s[0] - 'a' + 1;
            int last = s[n - 1] - 'a' + 1;
            int mini = min(first, last);
            int a = total - mini;
            int b = mini;

            int diff = a - b;
            cout << "Alice " << diff;
        }
    }
    cout << endl;
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
