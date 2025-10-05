// with optimized queue using pairs
#include <bits/stdc++.h>
using namespace std;
// it uses C++ 14

void solve()
{
    int q;
    cin >> q;
    queue<pair<int, int>> que;
    while (q--)
    {
        int temp;
        cin >> temp;
        if (temp == 1)
        {
            int c, x;
            cin >> c >> x;
            que.push({c, x});
        }
        else
        {
            int k;
            cin >> k;
            long long sum = 0;

            while (k > 0 && !que.empty())
            {
                auto [count, value] = que.front();

                if (count <= k)
                {
                    sum += (long long)count * value;
                    k -= count;
                    que.pop();
                }
                else
                {
                    sum += (long long)k * value;
                    que.front().first = count - k;
                    k = 0;
                }
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
