#include <bits/stdc++.h>
using namespace std;
// i'll use two pointer approach
int bsearch(vector<int> &nums, int i, int lower)
{
    int target = lower - nums[i];
    // linear search
    for(int k=0; k<nums.size(); k++){
        if(nums[k]>=target) return k;
    }
    return -1;
}

long long countFairPairs(vector<int> &nums, int lower, int upper)
{
    long long count = 0;
    sort(nums.begin(), nums.end());

    int l = 0;
    int r = bsearch(nums, l, lower);
    while(r<0){
        l++;
        int r = bsearch(nums, l, lower);
    }
    cout<<r<<endl;

    while(l<nums.size()){
        if((nums[r]+nums[l])<=upper){
            count++;
            r++;
        }
        else l++;
    }
    return count;
}

int main()
{
    vector<int> nums = {1,7,9,2,5};
    // 1 2 5 7 9
    int lower = 11;
    int upper = 11;
    cout << countFairPairs(nums, lower, upper);
    return 0;
}