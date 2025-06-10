#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> &a)
{
    // code
    if (n == 2)
    {
        cout << "yes" << endl;
        return;
    }
    sort(a.begin(), a.end());
    long long k = a[0] + a[n - 1];
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
    {
        um[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        // we're at a[0], we need k-a[0]
        int needed = k - a[i];
        if (um[needed] > 0)
        {
        }
        else
            cout << "no" << endl;
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
    int t;
    cin >> t;
    while (t--)
    {
        // input
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        solve(n, a);
    }

    return 0;
}
