#include <bits/stdc++.h>
using namespace std;

// did this myself, after a long time

int minimumCost(vector<int> &cost)
{
    sort(cost.begin(), cost.end());
    int n = cost.size();
    int res = 0;
    int i = n - 1;
    for (; i >= 0; i -= 3)
    {
        if (i >= 2)
        {
            res += cost[i] + cost[i - 1];
        }
        else
            break;
    }
    while (i >= 0)
    {
        res += cost[i];
        i--;
    }
    return res;
}
int main()
{
}