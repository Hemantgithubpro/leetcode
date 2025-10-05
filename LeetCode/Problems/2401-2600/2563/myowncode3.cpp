#include <bits/stdc++.h>
using namespace std;

// this is the continuation of myowncode2.cpp i'll try to lessen the time complexity

int bsearch(vector<int>& nums, int i, int lower){
    int target=lower-nums[i];
    if(i>=nums.size()-1) return -1;
    int left = i+1, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left; // Return the position where the target would be inserted
}

bool iffair(vector<int>& nums, int l, int r, int lower, int upper){
    if(r>=nums.size()) return false;
    if(l<0) return false;
    if(l>=r) return false;
    long a = nums[l]+nums[r];
    if((a>=lower) && (a<=upper)) return true;
    return false;
}



long long countFairPairs(vector<int>& nums, int lower, int upper) {
    long long count=0;       
    sort(nums.begin(),nums.end());
    // [0,1,4,4,5,7]
    //  i           
    int i=0;
    while(i<nums.size()){
        int j= bsearch(nums,i,lower);
        for(; nums[j]+nums[i]<=upper; j++){
            count++;
        }
        

        i++;
    } 
    // for(int i=0; i<nums.size(); i++){
    //     for(int j=i; j<nums.size(); j++){
    //         if(iffair(nums, i, j, lower, upper)) count++;
    //     }
    // }
    return count;
    
}

int main(){
    // vector<int> nums= {0,1,7,4,4,5};
    // int lower=3;
    // int upper=6;
    vector<int> nums = {1,7,9,2,5};
    int lower = 11;
    int upper = 11;
    cout<<countFairPairs(nums,lower,upper);
    return 0;
}