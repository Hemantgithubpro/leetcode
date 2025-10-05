#include <bits/stdc++.h>
using namespace std;

bool iszero(vector<int> &a)
{
    int temp = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        temp = temp ^ a[i];
    }
    if (temp == 0)
        return true;
    return false;
}

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

    int x = -1;
    for (int i = 0; i < 257; i++)
    {
        vector<int> temp = a;
        for (int j = 0; j < n; j++)
        {
            temp[j] = temp[j] ^ i;
        }
        if (iszero(temp))
        {
            x = i;
            break;
        }
    }
    cout << x << endl;
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
