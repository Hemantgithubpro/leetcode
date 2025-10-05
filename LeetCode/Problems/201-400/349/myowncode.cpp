#include <bits/stdc++.h>
using namespace std;

// This is not the optimal approach as it has TC:O(n*m) where n=nums1.size() and m=nums2.size()

bool ifFound(vector<int>& a, int val){
    for(int i=0; i<a.size(); i++){
        if(a[i]==val) return true;
    }
    return false;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> us;
    // sort(nums1.begin(), nums1.end());
    // sort(nums2.begin(), nums2.end());
    if(nums1.size()<=nums2.size()){
        for(int i=0; i<nums1.size(); i++){
            if(ifFound(nums2,nums1[i])) us.insert(nums1[i]);
        }
    }
    else{
        for(int i=0; i<nums2.size(); i++){
            if(ifFound(nums1,nums2[i])) us.insert(nums2[i]);
        }
    }

    vector<int> result;
    for(auto it: us){
        result.push_back(it);
    }
    return result;

}

// nums1=[4,9,5] -> [4,5,9]
// nums2=[9,4,9,8,4] -> [4,4,8,9,9]