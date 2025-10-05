#include <bits/stdc++.h>
using namespace std;

// this brute force method worked, but memory limit exceeded till 29/54 but then i fixed it in 'iffair' funcn by '& nums' taking its reference, instead of taking by value.

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
    for(int i=0; i<nums.size(); i++){
        for(int j=i; j<nums.size(); j++){
            if(iffair(nums, i, j, lower, upper)) count++;
        }
    }
    return count;
    
}

int main(){
vector<int> nums={1,7,9,2,5};
    int lower=11;
    int upper=11;
    cout<<countFairPairs(nums,lower,upper);
    return 0;
}