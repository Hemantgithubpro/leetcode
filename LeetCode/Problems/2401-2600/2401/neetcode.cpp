// we're told every & of every pair has to be 0, simply means that take the & of all the elements of that subarray, if its 0 then its a nice.
// we'll do sliding window, instead of finding each subarray and checking it.

#include <bits/stdc++.h>
using namespace std;

int longestNiceSubarray(vector<int>& nums) {
    int res=0;
    int l=0;
    int cur=0;  // bitmask

    for(int r=0; r<nums.size(); r++){
        while(cur&nums[r]){
            cur=cur^nums[l];
            l++;
        }
        res=max(res,r-l+1);
        cur=cur|nums[r];
        // cur=cur^nums[r]; //both valid
    }

    return res;
    // [1,3,8.48,10]
    // sliding window: two condn, 1. expanding and 2. shrinking
    // 1. expanding, r goes right ...
    // for setting cur&num[i] we use 'or'.
    
    // 2. shrinking, l goes right ...
    // before moving 'l' forward, we have to remove nums[l] from cur, for that we use xor.
}

int main(){

}