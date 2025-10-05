#include <bits/stdc++.h>
using namespace std;

// did it in first try, but still worst time complexity is O(n)
int maximumCount(vector<int>& nums) {   // nums is already sorted in non-decending order
    int neg=0;
    int pos=0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]<0) neg++;
        else if(nums[i]>0) pos++;
    }
    return max(pos,neg);
}

// another optimal way, since vector is already sorted, search the middle index
// another time
// int maximumCount(vector<int>& nums){
//     int left=0;
//     int right=nums.size()-1;
//     while(left<right){
//         int mid=left+(right-left)/2;
//         if(nums[mid]<0){

//         }
//         else if(nums[mid]==0){

//         }
//         else{

//         }
//     }

// }

int main(){
    vector<int> nums ={-2,-1,-1,0,0,1,2,3};
    cout<<maximumCount(nums);
}