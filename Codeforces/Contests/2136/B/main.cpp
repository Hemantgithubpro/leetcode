#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    int run = 0;
    bool bad = false;
    for (char c : s)
    {
        if (c == '1')
        {
            if (run++ >= k)
            {
                bad = true;
                break;
            }
        }
        else
            run = 0;
    }
    if (bad)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    vector<int> p(n);
    vector<int> zeros, ones;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            zeros.push_back(i);
        else
            ones.push_back(i);
    }
    int cur = n;
    for (int idx : zeros)
        p[idx] = cur--;
    for (int idx : ones)
        p[idx] = cur--;
    // sort(p.begin(), p.end());
    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << ' ';
        cout << p[i];
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
