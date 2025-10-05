#include <iostream>
#include <vector>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N, Q;
    cin >> N >> Q;

    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> queries[i];
    }

    vector<bool> black(N + 1, false);

    for (int i = 0; i < Q; i++)
    {
        black[queries[i]] = !black[queries[i]];

        int intervals = 0;
        bool in_interval = false;

        for (int j = 1; j <= N; j++)
        {
            if (black[j] && !in_interval)
            {
                intervals++;
                in_interval = true;
            }
            else if (!black[j] && in_interval)
            {
                in_interval = false;
            }
        }

        cout << intervals << "\n";
    }

    return 0;
}