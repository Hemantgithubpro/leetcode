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
    int ans=0;
    for(int i=0; i<nums.size()-k+1; i++){
        unordered_map<int,int> um;
        int r=k+i-1;
        for(int l=0; l<=r; l++){
            um[nums[l]]++;
        }
        int l=0;
        while(r<nums.size()){
            if(um.size()==k){
                ans++;
            }
            r++;
            um[nums[r]]++;
            um[nums[l]]--;
            if(um[nums[l]]==0) um.erase(nums[l]);
            l++;
        }
    }
    return ans;
}

int main(){
    vector<int> num={1,3,1,2,2};
    // vector<int> num={5,5,5,5};
    cout<<countCompleteSubarrays(num);
}