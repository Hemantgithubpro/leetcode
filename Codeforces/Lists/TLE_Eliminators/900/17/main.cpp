#include <bits/stdc++.h>
using namespace std;

bool isequal(vector<int> &a)
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (a[i] != a[i + 1])
            return false;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (isequal(a))
    {
        cout << 0 << endl;
        return;
    }

    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
    {
        um[a[i]]++;
    }
    int mostoccur = 0;
    int occur = 0;
    for (int i = 0; i < n; i++)
    {
        if (um[a[i]] > occur)
        {
            occur = um[a[i]];
            mostoccur = a[i];
        }
    }

    // now i've the most occuring int, i've to make the original array full of this int only.
    sort(a.begin(), a.end());
    int ops = 0;
    int needed = n - um[mostoccur];
    while (needed > 0)
    {
        // copying
        ops++;

        // replacing two
        if (needed >= 2)
        {
            ops += 2;
            needed -= 2;
        }
        else if (needed == 1)
        {
            ops++;
            needed--;
        }
    }
    cout << ops << endl;
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
