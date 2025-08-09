#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    // code
    int n, q;
    cin >> n >> q;

    vector<ll> bags(n);
    ll total = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> bags[i];
        total += bags[i];
    }

    vector<ll> freq(1000001, 0);
    for (ll x : bags)
    {
        freq[x]++;
    }

    vector<ll> result(1000001, -1);
    ll sum = 0;
    ll count = 0;

    for (int b = 1000000; b >= 1; --b)
    {
        if (freq[b] > 0)
        {
            sum += freq[b] * (b - 1);
            count += freq[b];
        }
        if (count > 0)
        {
            result[b] = sum + b;
        }

        ll next = b - 1;
        while (next >= 1 && freq[next] == 0)
        {
            if (count > 0)
            {
                result[next] = result[b] - count;
            }
            next--;
        }
        b = next + 1;
    }

    for (int i = 0; i < q; ++i)
    {
        ll b;
        cin >> b;
        if (b > 1000000 || result[b] == -1 || result[b] > total)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << result[b] << "\n";
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    // int t;
    // cin >> t;
    // while (t--) {
    // input
    solve();
    // }

    return 0;
}
