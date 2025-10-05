#include <bits/stdc++.h>
using namespace std;
// still not able to understand the solution of concept of buckets.
vector<int> singleNumber(vector<int>& nums) {
    // with brute force: hashing.
    map<int,int> mpp;
    for(int i=0; i<nums.size(); i++){
        mpp[nums[i]]++;
    }
    vector<int> ans;
    for(auto it:mpp){
        if(it.second==1) ans.push_back(it.first);
    }
    return ans;

}

int main(){
    
}