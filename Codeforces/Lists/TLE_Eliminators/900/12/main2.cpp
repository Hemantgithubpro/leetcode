#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // O(n^2)
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    // int mini = *min_element(a.begin(), a.end());
    // int maxi = *max_element(a.begin(), a.end());

    // int maybeachieved = maxi - mini;

    // if (a[n - 1] - a[0] == maybeachieved || a[n - 1] == maxi || a[0] == mini)
    // {
    //     cout << maybeachieved << endl;
    //     return;
    // }

    // int maxindex = 0, minindex = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (a[i] == maxi)
    //         maxindex = i;
    //     if (a[i] == mini)
    //         minindex = i;
    // }

    // // now i have index of maxi and mini
    // if (abs(maxindex - minindex) < 2)
    // {
    //     cout << maybeachieved << endl;
    //     return;
    // }

    int couldbe = 0;

    // couldbe = max(couldbe, abs(a[n - 1] - mini));
    // couldbe = max(couldbe, abs(maxi - a[0]));

    for (int i = 1; i < n; i++)
    {
        couldbe = max(couldbe, abs(a[i] - a[i - 1]));
    }
    for (int i = 1; i < n; i++)
    {
        couldbe = max(couldbe, abs(a[i] - a[0]));
    }
    for (int i = 0; i < n-1; i++)
    {
        couldbe = max(couldbe, abs(a[n-1] - a[i]));
    }

    cout << couldbe << endl;
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
