#include <bits/stdc++.h>
using namespace std;

// did with claude but figured out the concept.
int bsearch(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int result = nums.size();
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

long long countFairPairs(vector<int> &nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    long long count = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        // Find the first index where nums[j] >= lower - nums[i]
        int low = bsearch(nums, lower - nums[i]);
        // Find the first index where nums[j] > upper - nums[i]
        int high = bsearch(nums, upper - nums[i] + 1);
        
        // Count pairs between low and high, excluding the current index
        if (low < nums.size()) {
            // Exclude the current number from the count if it's in range
            if (low <= i && i < high) {
                count += high - low - 1;
            } else {
                count += high - low;
            }
        }
    }
    
    return count / 2; // Each pair was counted twice
}

int main()
{
    vector<int> nums = {1,7,9,2,5};
    // 1 2 5 7 9
    int lower = 11;
    int upper = 11;
    cout << countFairPairs(nums, lower, upper);
    return 0;
}