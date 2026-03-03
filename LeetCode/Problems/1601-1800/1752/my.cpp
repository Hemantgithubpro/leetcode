#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int count = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] <= nums[i])
                continue;
            else
                count++;
        }
        if (nums[nums.size() - 1] > nums[0])
            count++;
        if (count > 1)
            return false;
        else
            return true;
    }
};

int main()
{
}