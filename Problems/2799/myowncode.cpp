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
    int dist=noofdist(nums);
    unordered_map<int,int> um;
    int l=0, r=0;
    int ans=0;
    while(r<nums.size()){
        um[nums[r]]++;
        while(um.size()==dist){
            ans++;
            um[nums[l]]--;
            if(um[nums[l]]==0) um.erase(nums[l]);
            l++;
        }
        r++;
    }
    return ans;
}

int main(){
    
}