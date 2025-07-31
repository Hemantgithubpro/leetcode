#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    ll n;
    cin >> n;
    vector<int> s(n);
    ll freq0 = 0, freq1 = 0;
    ll score = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        if (s[i] == 0)
            freq0++;
        else if (s[i] == 1)
            freq1++;
        else
            score += s[i];
    }

    // sort(s.begin(), s.end());

    ll pairof01 = min(freq0, freq1);
    score += 2 * pairof01;
    ll rest = max(freq0, freq1)-pairof01;
    score += rest;
    cout << score << endl;
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
