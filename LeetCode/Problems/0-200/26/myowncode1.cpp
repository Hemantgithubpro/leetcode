#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // takes space
    // int removeDuplicates(vector<int>& nums) {
    //         vector<int> a;
    //         a.push_back(nums[0]);
    //         int temp=nums[0];
    //         for(int i=1; i<nums.size(); i++){
    //             if(nums[i]==temp) continue;
    //             else{
    //                 temp=nums[i];
    //                 a.push_back(temp);
    //             }
    //         }
    //         nums=a;
    //         return a.size();
    // }

    int removeDuplicates(vector<int> &nums)
    {
        // two pointer
        int n = nums.size();
        int start = 0;
        int i = 1;
        if (n == 1)
            return 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[start] != nums[i])
            {
                start++;
                nums[start] = nums[i];
            }
        }
        return start + 1;
    }
};

int main()
{
    // this was the brute force solution, not the most optimal solution, next time I'll try two pointer approach, to do within just one for loop.
    vector<int> nums = {2, 5, 2, 7, 1};
    // cout<<removeDuplicates(nums);
}