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
    for (int i = 1; i < n - 1; i++)
    {
        while (a[i + 1] % a[i] == 0 || a[i] % a[i - 1] == 0)
        {
            a[i]++;
        }

        // for (int i = 1; i < n-1; i++)
        // {
        //     while (a[i] % a[i - 1] == 0){

        //         a[i-1]++;
        //     }
        // }
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
