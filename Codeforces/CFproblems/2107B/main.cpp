#include <bits/stdc++.h>
using namespace std;
// easily accepted.
int findmaxindex(vector<int> &a)
{
    int maxi = INT_MIN;
    for (int i = 0; i < a.size(); i++)
    {
        maxi = max(maxi, a[i]);
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == maxi)
            return i;
    }
}

int findminindex(vector<int> &a)
{
    int mini = INT_MAX;
    for (int i = 0; i < a.size(); i++)
    {
        mini = min(mini, a[i]);
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == mini)
            return i;
    }
}

void solve(int n, int k, vector<int> &a)
{
    a[findmaxindex(a)]--;
    if ((a[findmaxindex(a)] - a[findminindex(a)]) > k)
    {
        cout << "Jerry" << endl;
        return;
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    if (sum % 2)
        cout << "Jerry" << endl;
    else
        cout << "Tom" << endl;
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
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        solve(n, k, a);
    }

    return 0;
}
