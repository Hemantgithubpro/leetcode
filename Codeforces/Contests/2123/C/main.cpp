#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(ll n, vector<ll> &a)
{
    vector<ll> prefixMin(n), suffixMax(n);
    prefixMin[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        prefixMin[i] = min(prefixMin[i - 1], a[i]);
    }
    suffixMax[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixMax[i] = max(suffixMax[i + 1], a[i]);
    }
    string answer(n, '0');
    for (int i = 0; i < n; i++)
    {
        if (a[i] == prefixMin[i] || a[i] == suffixMax[i])
        {
            answer[i] = '1';
        }
    }
    cout << answer << "\n";
}

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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        solve(n, a);
    }

    return 0;
}
