#include <bits/stdc++.h>
using namespace std;

int maxSumDivThree(vector<int> &nums)
{
    int sumDiv = 0;
    vector<int> nonDiv;
    for (int n : nums)
    {
        if (n % 3 == 0)
            sumDiv += n;
        else
            nonDiv.push_back(n);
    }

    vector<int> r1, r2;
    int extraSum = 0;
    for (int x : nonDiv)
    {
        extraSum += x;
        if (x % 3 == 1)
            r1.push_back(x);
        else
            r2.push_back(x);
    }
    sort(r1.begin(), r1.end());
    sort(r2.begin(), r2.end());

    int total = sumDiv + extraSum;
    int mod = total % 3;
    if (mod == 0)
        return total;

    int remove = INT_MAX;
    if (mod == 1)
    {
        if (!r1.empty())
            remove = min(remove, r1[0]);
        if (r2.size() >= 2)
            remove = min(remove, r2[0] + r2[1]);
    }
    else // mod == 2
    {
        if (!r2.empty())
            remove = min(remove, r2[0]);
        if (r1.size() >= 2)
            remove = min(remove, r1[0] + r1[1]);
    }

    if (remove == INT_MAX)
        return 0;
    return total - remove;
}