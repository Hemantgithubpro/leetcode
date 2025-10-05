#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> &a)
{
    // code
    int mindiff = INT_MAX;
    
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
        {
            cout << 0 << endl;
            return;
        }
        mindiff=min(mindiff,abs(a[i]-a[i-1]));
    }

    int ans=mindiff/2;
    ans++;
    cout<<ans<<endl;
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
