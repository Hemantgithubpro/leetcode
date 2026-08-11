#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingInteger(vector<int> &nums)
    {
        set<int> us;
        for (int num : nums)
            us.insert(num);
        int n = nums.size();
        int start = nums[0];
        int sum = start;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else
                break;
        }
        while (us.count(sum))
            sum++;
        return sum;
    }
};