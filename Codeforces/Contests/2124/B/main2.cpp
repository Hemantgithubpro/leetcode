#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long ans = 0;
        int minVal = a[0];
        for (int i = 0; i < n; i++)
        {
            minVal = min(minVal, a[i]);
            ans += minVal;
        }

        for (int j = 1; j < n; j++)
        {
            for (int i = 0; i < j; i++)
            {
                long long sum = 0;
                minVal = (i == 0) ? a[0] + a[j] : a[0];
                sum += minVal;

                for (int k = 1; k <= j; k++)
                {
                    if (k == i)
                    {
                        minVal = min(minVal, a[k] + a[j]);
                    }
                    else if (k == j)
                    {
                        minVal = min(minVal, 0);
                    }
                    else
                    {
                        minVal = min(minVal, a[k]);
                    }
                    sum += minVal;
                }

                ans = min(ans, sum);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}