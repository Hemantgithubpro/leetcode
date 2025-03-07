#include <bits/stdc++.h>
using namespace std;

// vector<int> removeone(vector<int> a, int index){
//     if(index==a.size()-1) a.resize(a.size()-1);
//     else
//     {for(int i=index; i<a.size();i++){
        
//         }
//     }
// }

int minCost(vector<int>& nums) {
    int count=0;
    while(nums.size()>=3){
        int maxim = 0;
        vector<int> a;
        for(int i=0;i<3; i++){
            a.push_back(nums[i]);
        }
        sort(a.begin(),a.end());
        maxim=a[2];
        nums.erase(nums.begin()+0,nums.begin()+3);
        nums.insert(nums.begin()+0,a[0]);
        count=count+maxim;
        
        // if(nums[0]>nums[1]){
        //     maxim=max(nums[0],nums[2]);
            
        // }
        // else if(nums[0]<nums[1]){
        //     maxim=max(nums[1],nums[2]);
            
        // }
        // else{
            
        // }
        // maxim=max(nums[0],nums[1]);
        // maxim=max(nums[2],maxim);
        // count=count+maxim;
        // nums.erase(nums.begin()+0,nums.begin()+3);
    }
    
    if(nums.size()<3){
        count=count+max(nums[0],nums[1]);
    }
    return count;
}

int main(){
    // vector<int> nums = {6,2,8,4};
    vector<int> nums = {2,1,3,3};
    cout<<minCost(nums);
    // // Remove elements in the range [1, 4)
    // v.erase(v.begin() + 1, v.begin() + 4);

    // for (auto i : v)
    //     cout << i << " ";
    return 0;   
}