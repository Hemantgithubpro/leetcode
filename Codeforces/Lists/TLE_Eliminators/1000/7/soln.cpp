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

    vector<int> long_a(2 * n + 1, 0);
    vector<int> long_b(2 * n + 1, 0);

    // two pointer approach
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
            ans++;
        else
        {
            long_a[a[i - 1]] = max(long_a[a[i - 1]], ans);
            ans = 1;
        }
    }
    long_a[a[n - 1]] = max(long_a[a[n - 1]], ans);

    ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (b[i] == b[i - 1])
            ans++;
        else
        {
            long_b[b[i - 1]] = max(long_b[b[i - 1]], ans);
            ans = 1;
        }
    }
    long_b[b[n - 1]] = max(long_b[b[n - 1]], ans);

    int answer = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        answer = max(answer, long_a[i] + long_b[i]);
    }

    cout << answer << endl;
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
