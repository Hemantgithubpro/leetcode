#include <bits/stdc++.h>
using namespace std;

int maxi(vector<int>& nums){
    int maxx=0;
    for(int i=0; i<nums.size(); i++){
        maxx=max(maxx,nums[i]);
    }
    return maxx;
}
long long countSubarrays(vector<int>& nums, int k) {
    int maxx=maxi(nums);
    int r=0;
    long long ans=0;
    map<int,int> mpp; 
    for(int l=0; l<nums.size(); l++){
        while(r<nums.size() && mpp[maxx]<k){
            mpp[nums[r]]++;
            r++;
        }
        if(mpp[maxx]>=k){
            ans+=(nums.size()-r+1);
        }
        mpp[nums[l]]--;
    }
    return ans;
}

int main(){
    // vector<int> n={1,3,2,3,3};
    vector<int> n={2,2,2,2,1,3,3,2,2,1,1,3,1,1,2,3,2,1,1,2,1,1,2,1,2,1,2,1,3,1,3,3};
    int k=5;
    cout<<countSubarrays(n,k)<<endl;
}