#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> v(n + 1, true);
        for (int i = 2; i * i <= n; i++)
        {
            if (v[i] == true)
            {
                for (int j = i * i; j <= n; j += i)
                    v[j] = false;
            }
        }

        int ans = 0;
        for (int i = 2; i < n; i++)
        {
            if (v[i])
                ans++;
        }
        return ans;
    }
};