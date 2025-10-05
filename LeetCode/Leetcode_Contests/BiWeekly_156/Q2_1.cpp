#include <bits/stdc++.h>
using namespace std;

// time limit exceeded for 926/968 testcases.

int findmin(vector<int>& nums){
    int min=INT_MAX;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]!=0){
            if(min>nums[i]) min=nums[i];
        }
    }
    return min;
}

bool isnotallzero(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
            return true;
    }
    return false;
}

int minOperations(vector<int> &nums) {
    // Handle empty case
    if (nums.empty()) return 0;
    
    // Use a map to store frequency of each value
    map<int, int> freq;
    for (int num : nums) {
        if (num > 0) {  // Skip zeros
            freq[num]++;
        }
    }
    
    // Count operations
    int operations = 0;
    
    // Process numbers from smallest to largest
    while (!freq.empty()) {
        // Get smallest value (first element in ordered map)
        auto it = freq.begin();
        int minVal = it->first;
        int minCount = it->second;
        
        // Remove this value
        freq.erase(it);
        
        // Increment operation count
        operations++;
        
        // Adjust counts for remaining values
        if (!freq.empty()) {
            auto next = freq.begin();
            next->second -= minCount;
            if (next->second <= 0) {
                freq.erase(next);
            }
        }
    }
    
    return operations;
}
int main()
{
    // vector<int> nums1 = {1,2,1,2,1,2};
    // vector<int> nums1 = {3,1,2,1};
    vector<int> nums1 = {4,3,4,6};
    // 1 2 1 2 1 2
    // 0 2 0 2 0 2
    //   a 
    // 0 0 0 0 0 0
    cout<<minOperations(nums1);
}