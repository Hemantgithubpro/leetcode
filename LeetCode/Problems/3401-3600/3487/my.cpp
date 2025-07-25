#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int> &nums)
{
    unordered_set<int> us;
    for (int n : nums)
    {
        us.insert(n);
    }
    int maxi = *max_element(nums.begin(), nums.end());
    int ans = maxi;
    for (auto it : us)
    {
        if (it > 0 && it != maxi)
            ans += it;
    }
    return ans;
}
int main()
{
    vector<int> nums = {-100};
    cout << maxSum(nums);
    return 0;
}