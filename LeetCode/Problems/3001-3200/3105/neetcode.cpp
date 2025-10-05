#include <bits/stdc++.h>
using namespace std;

int longestMonotonicSubarray(const vector<int>& nums) {
  int cur=1; // current length of subarray
  int res=1; // result: max value
  int increasing=0; // 1:increasing, -1:decreasing, 0:neither , it tracks the current trend of the subarray

  for(int i=1; i<nums.size(); i++){
    if(nums[i-1]<nums[i]){ // checking if the subarray is increasing
      if(increasing>0)  // if the subarray is already increasing
        cur++;
      else{ // if the subarray was not increasing, we can reset the length of subarray to be 2
        cur=2;
        increasing=1;
      }
    }
    else if(nums[i-1]>nums[i]){ // checking if the subarray is decreasing
      if(increasing<0) // if the subarray is already decreasing
        cur++;
      else{ // if the subarray was not decreasing, we can reset the length of subarray to be 2
        cur=2;
        increasing=-1;
      }
    }
    else{ // if the subarray is neither increasing nor decreasing
      cur=1;  // we reset current to be 1, because it neither increases nor decreases
      increasing=0; // we reset increasing to be 0, because it neither increases nor decreases
    }
    res=max(res,cur); // updating the result after each iteration
  }


  return res;
}