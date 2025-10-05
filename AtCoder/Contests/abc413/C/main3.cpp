// with queue
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    // q queries
    queue<int> que;
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
                que.push(x);
            }
        }
        else
        {
            int k;
            cin >> k;
            int sum = 0;
            while (k--)
            {
                sum += que.front();
                que.pop();
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
