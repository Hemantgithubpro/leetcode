// this is from the hint only
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
    int k=noofdist(nums);
    // sliding windows of size k,k+1,k+2,...,nums.size()
    for(int i=0; i<nums.size()-k; i++){
        unordered_map<int,int> um;
        int l=0;
        int r=k+i;
        while(r<nums.size()){
            for(int j=l; j<r; j++){
                um[nums[j]]++;
            }
        }
    }
    int ans=0;
    
}

int main(){
    
}