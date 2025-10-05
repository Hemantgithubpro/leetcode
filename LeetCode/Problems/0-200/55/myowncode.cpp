#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    int maxIndexreached = 0;
    int i = 0;
    while (i < nums.size())
    {
        if (maxIndexreached < i)
            return false;
        maxIndexreached = max(maxIndexreached, i + nums[i]);
        if (maxIndexreached >= nums.size())
            return true;
            i++;
    }
    return true;
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << canJump(nums);
}
