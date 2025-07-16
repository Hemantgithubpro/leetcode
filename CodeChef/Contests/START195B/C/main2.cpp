#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        vector<vector<ll>> dp_old(n + 1, vector<ll>(n + 1, LLONG_MIN));
        dp_old[0][0] = 0;
        vector<vector<ll>> dp_new(n + 1, vector<ll>(n + 1, LLONG_MIN));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                for (int c2 = 0; c2 <= j; c2++)
                {
                    dp_new[j][c2] = dp_old[j][c2];
                }
            }

            for (int j = 0; j <= i; j++)
            {
                for (int c2 = 0; c2 <= j; c2++)
                {
                    if (dp_old[j][c2] == LLONG_MIN)
                        continue;

                    if (j + 1 <= n)
                    {
                        ll candidate = dp_old[j][c2] + A[i];
                        if (candidate > dp_new[j + 1][c2])
                        {
                            dp_new[j + 1][c2] = candidate;
                        }
                    }

                    if (j + 1 <= n && c2 + 1 <= n)
                    {
                        ll candidate = dp_old[j][c2] + A[i] + j;
                        if (candidate > dp_new[j + 1][c2 + 1])
                        {
                            dp_new[j + 1][c2 + 1] = candidate;
                        }
                    }
                }
            }

            swap(dp_old, dp_new);
        }

        vector<ll> best(2 * n + 1, LLONG_MIN);
        for (int j = 0; j <= n; j++)
        {
            for (int c2 = 0; c2 <= j; c2++)
            {
                if (dp_old[j][c2] == LLONG_MIN)
                    continue;
                int cost = j + c2;
                if (cost <= 2 * n)
                {
                    if (dp_old[j][c2] > best[cost])
                    {
                        best[cost] = dp_old[j][c2];
                    }
                }
            }
        }

        vector<ll> ans_arr(2 * n + 1);
        ll cur = LLONG_MIN;
        for (int c = 0; c <= 2 * n; c++)
        {
            if (best[c] > cur)
            {
                cur = best[c];
            }
            ans_arr[c] = cur;
        }

        for (int k = 1; k <= 2 * n; k++)
        {
            cout << ans_arr[k];
            if (k < 2 * n)
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}