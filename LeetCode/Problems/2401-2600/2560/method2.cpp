// brute force, i guess
#include <bits/stdc++.h>
using namespace std;

int minCapability(vector<int>& nums, int k) {
    vector<int> a;
    // valid permutations, i would need 'k' no. of 'for' loops for this approach, which is not the optimal way.
    for(int i=0; i<nums.size()-2; i++){
        for(int j=i+2; j<nums.size(); j++){
            a.push_back(max(nums[i],nums[j]));
        }
    }

    int mini=INT_MAX;
    for(int i=0; i<a.size(); i++){
        mini=min(mini,a[i]);
    }
    return mini;
}

int main(){
    vector<int> nums={7,3,9,5};
    // 3 5 7 9
    int k=2;
    cout<<minCapability(nums,k);
    return 0;
}