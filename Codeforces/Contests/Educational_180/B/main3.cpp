#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a)
{
    int n = a.size();

    for (int i = 0; i < n - 1; i++)
    {
        if (abs(a[i] - a[i + 1]) <= 1)
        {
            return 0;
        }
    }

    if (n == 2)
    {
        return -1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int minVal = min(a[i], a[i + 1]);
        int maxVal = max(a[i], a[i + 1]);

        if (i > 0)
        {
            int left = a[i - 1];

            if (maxVal >= left - 1 && minVal <= left + 1)
            {
                return 1;
            }
        }

        if (i + 2 < n)
        {
            int right = a[i + 2];

            if (maxVal >= right - 1 && minVal <= right + 1)
            {
                return 1;
            }
        }

        bool hasOtherBeautifulPair = false;

        for (int j = 0; j < i - 1; j++)
        {
            if (abs(a[j] - a[j + 1]) <= 1)
            {
                hasOtherBeautifulPair = true;
                break;
            }
        }

        if (!hasOtherBeautifulPair)
        {
            for (int j = i + 2; j < n - 1; j++)
            {
                if (abs(a[j] - a[j + 1]) <= 1)
                {
                    hasOtherBeautifulPair = true;
                    break;
                }
            }
        }

        if (hasOtherBeautifulPair)
        {
            return 1;
        }
    }

    return 2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
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

        cout << solve(a) << "\n";
    }

    return 0;
}