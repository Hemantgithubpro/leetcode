#include <bits/stdc++.h>
using namespace std;

// time limit exceeded for 926/968 testcases.

int findmin(vector<int>& nums){
    int min=INT_MAX;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]!=0){
            if(min>nums[i]) min=nums[i];
        }
    }
    return min;
}

bool isnotallzero(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
            return true;
    }
    return false;
}

int minOperations(vector<int> &nums1)
{
    vector<int> nums=nums1;
    int ans=0;
    while (isnotallzero(nums))
    {
        int mini = findmin(nums);
        int a = -1, b = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i]==0 && a>=0 ){
                break;
            }
            else if (nums[i] == mini)
            {
                if(a<0) a=i;
                else b=i;
            }
        }
        cout<<"a: "<<a<<endl<<"b: "<<b<<endl;
        nums[a]=0;
        for(int i=a; i<=b; i++){
            if(nums[i]==mini) nums[i]=0;
            // cout<<nums[i]<<" ";
        }
        // cout<<endl;
        
        ans++;
        // cout<<ans<<endl;
        }
    return ans;
}

int main()
{
    // vector<int> nums1 = {1,2,1,2,1,2};
    // vector<int> nums1 = {3,1,2,1};
    vector<int> nums1 = {4,3,4,6};
    // 1 2 1 2 1 2
    // 0 2 0 2 0 2
    //   a 
    // 0 0 0 0 0 0
    cout<<minOperations(nums1);
}