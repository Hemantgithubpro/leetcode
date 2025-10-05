#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> &a)
{
    int j = 0;
    int maxi = 0;
    for (int i = 0; i < n ; i++)
    {
        if (a[i] == 0)
        {
            j++;
            maxi=max(maxi,j);
        }
        else j=0;
    }
    cout<<maxi<<endl;
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
