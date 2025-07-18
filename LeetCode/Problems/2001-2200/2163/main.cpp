#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumDifference(vector<int> &nums)
    {
        int n = nums.size() / 3;

        // For each position i, calculate the minimum sum of n elements from nums[0..i]
        vector<long long> minLeft(nums.size());
        priority_queue<int> maxHeap; // max heap for maintaining n smallest elements
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            maxHeap.push(nums[i]);
            sum += nums[i];

            if (maxHeap.size() > n)
            {
                sum -= maxHeap.top();
                maxHeap.pop();
            }

            if (maxHeap.size() == n)
            {
                minLeft[i] = sum;
            }
        }

        // For each position i, calculate the maximum sum of n elements from nums[i..2n-1]
        vector<long long> maxRight(nums.size());
        priority_queue<int, vector<int>, greater<int>> minHeap; // min heap for maintaining n largest elements
        sum = 0;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            minHeap.push(nums[i]);
            sum += nums[i];

            if (minHeap.size() > n)
            {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if (minHeap.size() == n)
            {
                maxRight[i] = sum;
            }
        }

        // Find the minimum difference
        long long result = LLONG_MAX;

        // The first part ends at position i, second part starts at position i+1
        // We need at least n elements before position i+1 and at least n elements from position i+1
        for (int i = n - 1; i < 2 * n; i++)
        {
            result = min(result, minLeft[i] - maxRight[i + 1]);
        }

        return result;
    }

};

int main()
{
    Solution sol;

    // Test case 1
    vector<int> nums1 = {3, 1, 2};
    cout << "Test 1: " << sol.minimumDifference(nums1) << endl; // Expected: -1

    // Test case 2
    vector<int> nums2 = {7, 9, 5, 8, 1, 3};
    cout << "Test 2: " << sol.minimumDifference(nums2) << endl; // Expected: 1

    return 0;
}