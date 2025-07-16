#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> us;
    for (int i = 0; i < nums.size(); i++)
    {
        if (us.find(nums[i]) != us.end())
        {
            return true;
        }
        us.insert(nums[i]);
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    cout << containsDuplicate(nums);
    return 0;
}