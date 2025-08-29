#include <bits/stdc++.h>
using namespace std;

long long flowerGame(int n, int m)
{
    long long ans = 0;
    if (n < 2 && m < 2)
        return 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2)
        {
            // y should be 2,4,6,...m
            ans += m / 2;
        }
        else
        {
            ans += m / 2;
            if (m % 2)
                ans++;
        }
    }
    return ans;
    // one more thing sum should be odd.
    // like n=5,m=3
    // valids are (1,2),(2,1)
}

int main()
{
}