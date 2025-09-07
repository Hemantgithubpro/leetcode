#include <bits/stdc++.h>
#define ll long long

using namespace std;
void solve()
{
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (k == 0)
    {
        cout << sum << endl;
        return;
    }

    vector<int> f(n + 2, 0);
    for (ll x : a)
    {
        if (x < n + 1)
            f[x]++;
    }

    int mex = 0;
    while (mex <= n && f[mex] > 0)
        mex++;

    if (mex == n)
        cout << sum << endl;
    else
    {
        int dup = -1;
        for (int i = 0; i < mex; i++)
        {
            if (f[i] >= 2)
            {
                dup = i;
                break;
            }
        }

        if (dup == -1)
        {
            ll s = 0;
            for (int i = 0; i < mex; i++)
            {
                s += i;
            }
            ll cnt = mex;
            ll s0 = s + mex * (n - cnt);

            if (n - mex == 1)
                cout << s0 << endl;
            else
            {
                ll s1 = s + (mex + 1) * (n - cnt);
                if (k == 1)
                    cout << s0 << endl;
                else
                {
                    if (k % 2 == 1)
                        cout << s0 << endl;
                    else
                        cout << s1 << endl;
                }
            }
        }
        else
        {
            ll cnt = 0;
            ll s = 0;
            for (int i = 0; i < mex; i++)
            {
                if (f[i] == 1)
                {
                    cnt++;
                    s += i;
                }
            }

            if (k == 1)
            {
                ll ans0 = s + mex * (n - cnt);
                cout << ans0 << endl;
            }
            else
            {
                ll t = dup * (dup - 1) / 2;
                ll s1 = t + dup * (n - dup);
                ll s2 = t + (dup + 1) * (n - dup);
                if (k % 2 == 0)
                    cout << s1 << endl;
                else
                    cout << s2 << endl;
            }
        }
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
