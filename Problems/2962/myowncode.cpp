#include <bits/stdc++.h>
using namespace std;

int maxi(vector<int>& nums){
    int maxx=0;
    for(int i=0; i<nums[i]; i++){
        maxx=max(maxx,nums[i]);
    }
    return maxx;
}
long long countSubarrays(vector<int>& nums, int k) {
    int maxx=maxi(nums);
    int l=0;
    int r=0;
    long long ans=0;
    map<int,int> mpp; 
    while(r<nums.size()){
        mpp[nums[r]]++;
        if(mpp[maxx]>=k){
            ans+=(nums.size()-r);
            mpp[nums[l]]--;
            l++;
            
        }
        r++;
    }
    return ans;
}

int main(){
    vector<int> n={1,3,2,3,3};
    int k=2;
    cout<<countSubarrays(n,k)<<endl;
}