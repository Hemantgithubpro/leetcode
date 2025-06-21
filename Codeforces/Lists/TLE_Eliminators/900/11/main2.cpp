#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // a[i+1]%a[i] != 0

    // making first element even
    if (a[0] % 2 == 1)
        a[0]++;

    // first element is even
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        { // 0,2,4,6
            if (a[i] % 2 != 0)
                a[i]++;
        }
        else
        { // 1,3,5,7
            if (a[i] % 2 == 0)
                a[i]++;
        }
    }

    // checking if same elements are not adjacent
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
            a[i + 1] += 2;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
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
