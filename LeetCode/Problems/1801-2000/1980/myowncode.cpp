#include <bits/stdc++.h>
using namespace std;

string xorofstrings(string &a, string &b)
{
    string ans = "";
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            ans += '1';
        else
            ans += '0';
    }
    return ans;
}
string findDifferentBinaryString(vector<string> &nums)
{
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
        ans = xorofstrings(ans, nums[i]);
    }
    return ans;
}

int main(){
    vector<string> nums={"01","10"};
    cout<<findDifferentBinaryString(nums);
}