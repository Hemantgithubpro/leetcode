#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
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
        vector<int> a(n);
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> ans;
        ans.push_back(a[0]);
        for (int i = 1; i < n; i++)
        {
            if (a[i - 1] <= a[i])
                ans.push_back(a[i]);
            else
            {
                ans.push_back(a[i]);
                ans.push_back(a[i]);
            }
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
