#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        um[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = m - b[i];
        if (um[temp] > 0)
        {
            um[temp]--;
        }
        else
        {
            int min_key = INT_MAX;
            for (const auto &p : um)
            {
                if (p.second > 0 && p.first < min_key)
                {
                    min_key = p.first;
                }
            }
            if (min_key != INT_MAX)
            {
                um[min_key]--;
                sum += min_key;
            }
        }
    }

    cout << sum << '\n';
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
    int t;
    cin >> t;
    while (t--)
    {
        // input
        solve();
    }

    return 0;
}
