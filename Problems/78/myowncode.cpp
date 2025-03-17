#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int subsets = 1 << nums.size();
    vector<vector<int>> ans;
    for(int num=0;num<subsets;num++){
        vector<int> l;
        for(int i=0; i<nums.size(); i++){
            if(num&(1<<i)) l.push_back(nums[i]);
        }
        ans.push_back(l);
    }
    return ans;
}

int main(){
    
}