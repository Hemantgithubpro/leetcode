#include <bits/stdc++.h>
#define ll long long

using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool poss = true;
    if (n > 1 && s[0] == '0' && s[1] == '1')
        poss = false;
    if (n > 1 && s[n - 2] == '1' && s[n - 1] == '0')
        poss = false;
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i - 1] == '1' && s[i] == '0' && s[i + 1] == '1')
        {
            poss = false;
            break;
        }
    }
    if (!poss)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<int> p(n);
    int i = 0;
    while (i < n)
    {
        if (s[i] == '1')
        {
            p[i] = i + 1;
            i++;
        }
        else
        {
            int j = i;
            while (j + 1 < n && s[j + 1] == '0')
                j++;
            for (int k = i; k < j; k++)
            {
                p[k] = k + 2;
            }
            p[j] = i + 1;
            i = j + 1;
        }
    }
    for (int k = 0; k < n; k++)
    {
        cout << p[k] << ' ';
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
