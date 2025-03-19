#include <bits/stdc++.h>
using namespace std;
// did it by looking at leetcode solution, my approach was mostly similar
int minOperations(vector<int>& nums) {
    int count=0;
    for(int i=2; i<nums.size(); i++){
        if(nums[i-2]==0){
            count++;
            nums[i-2]^=1;
            nums[i-1]^=1;
            nums[i]^=1;
        }
    }
    // see gfg of accumulate in cpp.
    int sum=accumulate(nums.begin(),nums.end(),0);
    if(sum==nums.size()) return count;
    return -1;
}
int main(){
    
}