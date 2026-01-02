#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size()/2;
        unordered_map<int,int> um;
        for(int a:nums){
            um[a]++;
            if(um[a]==n) return a;
        }
        return nums[0];
    }
};