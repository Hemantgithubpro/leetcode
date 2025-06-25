#include <bits/stdc++.h>
using namespace std;
// hash table

string findDifferentBinaryString(vector<string> &nums)
{
    int n = nums[0].size();
    for (int i = 0; i < n; i++)
    {
        unordered_set<char> us;
        for (int j = 0; j < nums.size(); j++)
        {
            us.insert(nums[j][i]);
        }
    }
    if (nums.size() == 1 && nums[0].size() == 1)
    {
        if (nums[0] == "0")
            return "1";
        else
            return "0";
    }
    string ans = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        // ans = xorofstrings(ans, nums[i]);
    }
    return ans;
}

int main()
{
    vector<string> nums = {"01", "10"};
    cout<<findDifferentBinaryString(nums);
    // cout << nums[0][1];
}