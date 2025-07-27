#include <bits/stdc++.h>
using namespace std;

bool isMonotonic(vector<int> &nums)
{
    if (nums.size() < 2)
        return true;
    // first check non equal
    int i = 0;
    int idx = 0;
    while (i < nums.size() - 1)
    {
        if (nums[i] != nums[i + 1])
        {
            idx = i;
            break;
        }
        i++;
    }
    // now i've the idx of unequal
    if (nums[idx] > nums[idx + 1])
    {
        for (int i = idx; i < nums.size() - 1; i++)
        {
            if (nums[i] < nums[i + 1])
                return false;
        }
        return true;
    }
    else
    {
        for (int i = idx; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
                return false;
        }
        return true;
    }
    return true;
}

int main()
{
}