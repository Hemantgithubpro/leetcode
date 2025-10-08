#include <bits/stdc++.h>
using namespace std;

// did in first try
int binarysearch(vector<int> &potions, long long target)
{
    int left = 0;
    int right = potions.size();
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if ((long long)potions[mid] >= target)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}
vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    int n = spells.size(), m = potions.size();
    sort(potions.begin(), potions.end());
    vector<int> pairs(n);

    for (int i = 0; i < n; i++)
    {
        int num = 0;
        long long target = success / (long long)spells[i];
        if (success % (long long)spells[i])
            target++;
        int idx = binarysearch(potions, target);
        num = m - idx;
        pairs[i] = num;
    }
    return pairs;
}