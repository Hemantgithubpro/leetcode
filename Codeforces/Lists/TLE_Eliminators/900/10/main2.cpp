#include <bits/stdc++.h>
using namespace std;

void solve(int n, int q, vector<int> &a, int b[][3])
{
    

    for (int i = 0; i < q; i++)
    {
        int l = b[i][0], r = b[i][1], k = b[i][2];
        long long sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (j + 1 >= l && j + 1 <= r)
            {
                sum += k;
            }
            else
            {
                sum += a[j];
            }
        }
        cout << (sum % 2 == 1 ? "YES" : "NO") << "\n";
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
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int b[q][3];
        for (int i = 0; i < q; i++)
        {
            cin >> b[i][0] >> b[i][1] >> b[i][2];
        }

        solve(n, q, a, b);
    }

    return 0;
}
