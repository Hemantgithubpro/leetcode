#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    // code
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n);
    ll sum = 0;
    ll m = LLONG_MAX;
    ll m2 = LLONG_MAX;
    ll count_m = 0;

    for (ll i = 0; i < n; i++)
    {
        cin >> A[i];
        sum += A[i];

        if (A[i] < m)
        {
            m2 = m;
            m = A[i];
            count_m = 1;
        }
        else if (A[i] == m)
            count_m++;
        else if (A[i] < m2)
            m2 = A[i];
    }

    if (count_m >= 2)
    {
        ll total = k * m;
        cout << sum + total << '\n';
    }
    else
    {
        ll a0 = (m + m2 + 1) / 2;
        ll b0 = a0 - (m + 1);
        ll current = b0;
        ll sum_b = 0;
        for (ll i = 0; i < k; i++)
        {
            if (current == 0)
                break;
            sum_b += current;
            current = current / 2;
        }
        ll total = k * (m + 1) + sum_b;
        cout << sum + total << '\n';
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
    ll t;
    cin >> t;
    while (t--)
    {
        // input
        solve();
    }

    return 0;
}
