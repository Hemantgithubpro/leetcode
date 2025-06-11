#include <bits/stdc++.h>
using namespace std;

bool isok(vector<int> &a, vector<int> &b)
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (a[i] + b[i] > a[i + 1] + b[i + 1])
            return false;
    }
    return true;
}

void solve(int n, vector<int> &a)
{
    vector<int> b;
    
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
