#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) { // we'll interpret as the longest subarray with at most k zeroes.
    int l=0;
    int len=0;
    int maxlen=0;
    int zeroes=0;
    for(int r=0;r<nums.size();r++){
        if(nums[r]==0) zeroes++;
        if(zeroes<=k){
            len=r-l+1;
            maxlen=max(len,maxlen);
        }
        else {
            // this logic i didn't think of.
            while (zeroes > k) {
                if (nums[l] == 0) zeroes--;
                l++;
            }
        }
    }
    return maxlen;
}

int main(){
    // vector<int> nums={1,1,1,0,0,0,1,1,1,1,0};
    vector<int> nums={0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k=3;
    cout<<longestOnes(nums,k);
}