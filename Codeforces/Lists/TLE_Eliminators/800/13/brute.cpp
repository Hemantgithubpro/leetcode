#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> &a)
{
    vector<int> b;
    vector<int> c;

    // c should not contain any divisors(denominators), b[i]%c[j]!=0
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] % a[j] == 0 && a[j]!=1 )
            {
                b.push_back(a[j]);
            }
        }
    }

    // for (int i = 0; i < n - 1; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (a[j] % a[i] == 0)
    //         {
    //             b.push_back(a[j]);
    //         }
    //     }
    // }


    for (int i = 0; i < n; i++)
    {
        bool isnotinb = true;
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j])
                isnotinb = false;
        }
        if (isnotinb)
            c.push_back(a[i]);
    }

    if (b.size() == 0 || c.size() == 0)
        cout << -1 << endl;
    else
    {

        cout << b.size() << " " << c.size() << endl;
        for (int i = 0; i < b.size(); i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < c.size(); i++)
        {
            cout << c[i] << " ";
        }
        cout<<endl;
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
