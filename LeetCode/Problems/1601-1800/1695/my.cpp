#include <bits/stdc++.h>
using namespace std;

int maximumUniqueSubarray(vector<int> &nums)
{
    int n = nums.size();
    int l = 0;
    int maxsum = 0;
    int currentSum = 0;
    unordered_set<int> seen;
    
    for (int r = 0; r < n; r++)
    {
        // If current element is already in the window, shrink from left
        while (seen.find(nums[r]) != seen.end())
        {
            seen.erase(nums[l]);
            currentSum -= nums[l];
            l++;
        }
        
        // Add current element to the window
        seen.insert(nums[r]);
        currentSum += nums[r];
        
        // Update maximum sum
        maxsum = max(maxsum, currentSum);
    }
    return maxsum;
}

int main()
{
    vector<int> nums = {4, 2, 4, 5, 6};
    cout << maximumUniqueSubarray(nums);
    return 0;
}