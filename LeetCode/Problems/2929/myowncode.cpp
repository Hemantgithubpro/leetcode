#include <bits/stdc++.h>
using namespace std;

long long distributeCandies(int n, int limit)
{
    // three children, each child can have (0 to limit) candies
    int temp = n - 2 * limit;
    int mini = max(0, temp);
    int maxi = min(n, limit);

    long long ans = 0;
    for (int i = mini; i <= maxi; i++)
    {
        int tworemain = n - i;

        int min2 = max(0, tworemain - limit);
        int max2 = min(tworemain, limit);

        ans += max2 - min2 + 1;
    }
    return ans;
}

int main()
{
}