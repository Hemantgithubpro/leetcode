#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        um[a[i]]++;
    }
    long long ans = 0;

    for (auto &p : um)
    {
        int freq = p.second;
        if (freq >= 2)
        {
            long long pair = (long long)freq * (freq - 1) / 2;
            long long rem = n - freq;
            ans += pair * rem;
        }
    }

    cout << ans << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--) {
    // input
    solve();
    // }

    return 0;
}
