#include <bits/stdc++.h>
using namespace std;

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

        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, LLONG_MIN));
        dp[0][0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                for (int c2 = j; c2 >= 0; c2--)
                {
                    if (dp[j][c2] == LLONG_MIN)
                        continue;

                    if (j + 1 <= n)
                    {
                        long long new_val = dp[j][c2] + A[i];
                        if (new_val > dp[j + 1][c2])
                        {
                            dp[j + 1][c2] = new_val;
                        }
                    }

                    if (j + 1 <= n && c2 + 1 <= n)
                    {
                        long long new_val = dp[j][c2] + A[i] + j;
                        if (new_val > dp[j + 1][c2 + 1])
                        {
                            dp[j + 1][c2 + 1] = new_val;
                        }
                    }
                }
            }
        }

        vector<long long> arr(2 * n + 1, LLONG_MIN);
        for (int j = 0; j <= n; j++)
        {
            for (int c2 = 0; c2 <= j; c2++)
            {
                long long cost = j + c2;
                if (cost <= 2 * n)
                {
                    if (dp[j][c2] > arr[cost])
                    {
                        arr[cost] = dp[j][c2];
                    }
                }
            }
        }

        vector<long long> ans_arr(2 * n + 1);
        long long cur = LLONG_MIN;
        for (int c = 0; c <= 2 * n; c++)
        {
            if (arr[c] > cur)
            {
                cur = arr[c];
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