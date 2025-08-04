#include <bits/stdc++.h>
using namespace std;

int findamn(vector<vector<int>> &fruits, int i)
{
    // it'll return the amount at pos i
    int n = fruits.size();
    int l = fruits[0][0], r = fruits[n - 1][0];
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (fruits[mid][0] == i)
            return fruits[mid][1];
        else if (fruits[mid][0] > i)
            l = mid - 1;
        else
            r = mid + 1;
    }
    return -1;
}

int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
{
    int l = startPos - k;
    if (startPos - k < 0)
        l = 0;
    int r = startPos + k;

    // window is l to r, inclusive

    // prefix sum
    vector<int> prefsum(r - l + 1, 0);
    
    for (int i = l+1; i <= r; i++)
    {
        int temp = findamn(fruits, i);
        if (temp != -1)
            prefsum[i] = prefsum[i - 1] + temp;
    }
}

int main()
{
}