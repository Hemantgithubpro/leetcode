#include <bits/stdc++.h>
using namespace std;
// from claude, i did it again, forgot about that i could've used hashmap.
class FindSumPairs
{vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq;  // Store frequency of nums2 elements

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        // Build frequency map
        for (int num : nums2) {
            freq[num]++;
        }
    }
    
    void add(int index, int val) {
        freq[nums2[index]]--;       // Decrease old value frequency
        nums2[index] += val;        // Update value
        freq[nums2[index]]++;       // Increase new value frequency
    }
    
    int count(int tot) {
        int result = 0;
        // For each number in nums1, find pairs using freq map
        for (int x : nums1) {
            result += freq[tot - x];
        }
        return result;
    }
};

int main()
{
}