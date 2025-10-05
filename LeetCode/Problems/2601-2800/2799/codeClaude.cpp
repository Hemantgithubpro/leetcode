#include <bits/stdc++.h>
using namespace std;

int noofdist(vector<int>& nums){
    unordered_set<int> us;
    for(int i=0; i<nums.size(); i++){
        us.insert(nums[i]);
    }
    return us.size();
}

int countCompleteSubarrays(vector<int>& nums) {
    int k = noofdist(nums);
    int ans = 0;
    
    // Using sliding window to count all complete subarrays
    unordered_map<int, int> um;
    
    for (int i = 0; i < nums.size(); i++) {
        // Start a new window at position i
        um.clear();
        for (int j = i; j < nums.size(); j++) {
            // Extend the window to include nums[j]
            um[nums[j]]++;
            
            // Check if this window has all distinct elements
            if (um.size() == k) {
                ans++;
            }
        }
    }
    
    return ans;
}

int main(){
    // vector<int> num={1,3,1,2,2};
    vector<int> num={5,5,5,5};
    cout<<countCompleteSubarrays(num);
    return 0;
}