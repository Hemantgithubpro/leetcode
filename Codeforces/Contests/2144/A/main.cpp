#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool valid(int a, int b, int c)
{
    return (a == b && b == c) || (a != b && b != c && c != a);
}

void solve()
{
    // input here only
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i];

    bool found = false;
    for (int l = 1; l < n && !found; l++)
    {
        for (int r = l + 1; r < n; r++)
        {
            int s1 = pref[l] % 3;
            int s2 = (pref[r] - pref[l]) % 3;
            int s3 = (pref[n] - pref[r]) % 3;
            if (valid(s1, s2, s3))
            {
                cout << l << " " << r << endl;
                found = true;
                break;
            }
        }
    }
    if (!found)
        cout << "0 0" << endl;
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
