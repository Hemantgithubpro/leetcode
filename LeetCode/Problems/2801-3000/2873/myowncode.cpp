#include <bits/stdc++.h>
using namespace std;

// brute force, O(n^3), and it worked
long long maximumTripletValue(vector<int> &nums)
{
    bool c = true;
    long long ans = 0;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                // long long triplet = (nums[i] - nums[j]) * nums[k];

                long long a = nums[i] - nums[j];
                long long b = nums[k];
                long long triplet = a * b;
                ans = max(ans, triplet);
                if (ans > 0)
                    c = false;
            }
        }
    }
    if (c)
        return 0;
    else
        return ans;
}

// Optimal Solution, O(n)
long long maximumTripletValue(vector<int> &nums)
{
    long maxTriplet = 0, maxElement = 0, maxDiff = 0;
    for (long num : nums)
    {
        maxTriplet = max(maxTriplet, maxDiff * num);
        maxDiff = max(maxDiff, maxElement - num);
        maxElement = max(maxElement, num);
    }
    return maxTriplet;
}

int main()
{
    vector<int> nums = {12, 6, 1, 2, 7};
    cout << maximumTripletValue(nums);
    return 0;
}