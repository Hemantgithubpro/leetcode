#include <bits/stdc++.h>
using namespace std;

bool canAliceWin(vector<int> &nums)
{
    int singlesum = 0, elsesum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] / 10 > 0)
            elsesum += nums[i];
        else
            singlesum += nums[i];
    }
    if (singlesum == elsesum)
        return false;
    return true;
}

int main()
{
}
