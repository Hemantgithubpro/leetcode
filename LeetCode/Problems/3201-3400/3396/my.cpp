#include <bits/stdc++.h>
using namespace std;

// did it on my own
bool alldisinct(unordered_map<int, int> &um)
{
    for (auto it = um.begin(); it != um.end(); it++)
    {
        if (it->second > 1)
            return false;
    }
    return true;
}

int minimumOperations(vector<int> &nums)
{
    unordered_map<int, int> um;
    for (int n : nums)
        um[n]++;
    int ans = 0;
    int i = 0;
    while (!alldisinct(um))
    {
        if (i+3 >= nums.size())
            return ans+1;
        um[nums[i]]--;
        um[nums[i + 1]]--;
        um[nums[i + 2]]--;
        i += 3;
        ans++;
    }
    return ans;
}

int main()
{
}
