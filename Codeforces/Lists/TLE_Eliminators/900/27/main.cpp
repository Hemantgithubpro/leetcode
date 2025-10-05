#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    // code
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    ll maxsum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        maxsum += (a[i] / x);
        if (a[i] % x > 0)
            maxsum++;
    }

    // i wont touch those numbers who are divisible by x.
    ll temp = 0;
    vector<ll> notdivisibles;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] % x > 0)
            notdivisibles.push_back(a[i]);
        else
            temp += (a[i] / x);
    }

    // sum of all notdivisibles
    ll temp2 = 0;
    for (ll i = 0; i < notdivisibles.size(); i++)
    {
        temp2 += notdivisibles[i];
    }
    ll sum2 = temp;
    sum2 += temp2 / x;
    if (temp2 % x > 0)
        sum2++;

    cout << sum2 << " " << maxsum << endl;
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
    ll t;
    cin >> t;
    while (t--)
    {
        // input
        solve();
    }

    return 0;
}
