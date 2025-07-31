#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    int c0 = 0, c1 = 0, c2 = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] == 0)
            c0++;
        else if (a[i] == 1)
            c1++;
        else if (a[i] == 2)
            c2++;
    }

    int total = c1 + 2 * c2;

    if (s < total)
    {
        for (int i = 0; i < n; ++i)
        {
            cout << a[i];
            if (i != n - 1)
                cout << " ";
        }
        cout << endl;
    }
    else if (s == total + 1)
    {
        vector<int> arr;
        arr.insert(arr.end(), c0, 0);
        arr.insert(arr.end(), c2, 2);
        arr.insert(arr.end(), c1, 1);
        for (int i = 0; i < arr.size(); ++i)
        {
            cout << arr[i];
            if (i != arr.size() - 1)
                cout << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
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
