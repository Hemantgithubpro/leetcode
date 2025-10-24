#include <bits/stdc++.h>
#define ll long long

using namespace std;
void solve()
{
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    bool has_B = false;
    for (char c : s)
        if (c == 'B')
        {
            has_B = true;
            break;
        }
    for (ll i = 0; i < q; i++)
    {
        ll a;
        cin >> a;
        if (a == 0)
        {
            cout << 0 << endl;
            continue;
        }
        if (!has_B)
        {
            cout << a << endl;
            continue;
        }
        ll total_time = 0;
        while (a > 0)
        {
            ll current_a = a;
            ll current_machine_idx = 0;
            bool hit_zero_in_cycle = false;
            for (ll step = 1; step <= n; step++)
            {
                if (s[current_machine_idx] == 'A')
                    current_a -= 1;
                else
                    current_a /= 2;
                if (current_a == 0)
                {
                    total_time += step;
                    a = 0;
                    hit_zero_in_cycle = true;
                    break;
                }
                current_machine_idx = (current_machine_idx + 1) % n;
            }
            if (!hit_zero_in_cycle)
            {
                total_time += n;
                a = current_a;
            }
        }
        cout << total_time << endl;
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
