#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k, int x)
{
    vector<int> ans;
    if (x != 1)
    {
        cout << "YES" << endl;
        vector<int> ans;
        while (n > 0)
        {
            ans.push_back(1);
            n--;
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    else // if x is '1'
    {
        if (k == 1)
        {
            cout << "NO" << endl;
        }
        else if (n % 2 == 0)
        {
            cout << "YES" << endl;
            vector<int> ans;
            while (n > 0)
            {
                ans.push_back(2);
                n = n - 2;
            }
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        else
        {
            // if n is odd, and there is no '1'
            if (k > 2)
            {
                cout << "YES" << endl;
                vector<int> ans;
                ans.push_back(3);
                n = n - 3;
                while (n > 0)
                {
                    ans.push_back(2);
                    n = n - 2;
                }
                cout << ans.size() << endl;
                for (int i = 0; i < ans.size(); i++)
                {
                    cout << ans[i] << " ";
                }
                cout << endl;
            }
            else
                cout << "NO" << endl;
        }
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
        int n, k, x;
        cin >> n >> k >> x;

        solve(n, k, x);
    }

    return 0;
}
