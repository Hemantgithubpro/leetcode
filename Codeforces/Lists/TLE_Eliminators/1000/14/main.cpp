#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        um[a[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        int temp = a[i];
        if (um[temp] <= 1)
        {
            cout << -1 << endl;
            return;
        }
    }
    vector<int> ab(n);
    iota(ab.begin(), ab.end(), 1);
    for (int i = 0; i < n; i++)
    {
        int lastoccur = i + um[a[i]] - 1;
        if (i == lastoccur || lastoccur >= n)
            continue;
        for (int j = i; j < lastoccur && j + 1 < n; j++)
        {
            swap(ab[j], ab[j + 1]);
        }
        i = lastoccur;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ab[i] << ' ';
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
