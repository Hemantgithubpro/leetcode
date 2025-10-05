#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    // q queries
    vector<int> a;
    while (q--)
    {
        int temp;
        cin >> temp;
        if (temp == 1)
        {
            int c, x;
            cin >> c >> x;
            for (int i = 0; i < c; i++)
            {
                a.push_back(x);
            }
        }
        else
        {
            int k;
            cin >> k;
            int validpos = 0;
            while (a[validpos] == -1)
                validpos++;
            int sum = 0;
            for (int i = validpos; i <= validpos + k; i++)
            {
                sum += a[validpos];
                a[validpos] = -1;
            }
            cout << sum << endl;
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

    solve();

    return 0;
}
