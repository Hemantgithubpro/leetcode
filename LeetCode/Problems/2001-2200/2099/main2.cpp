#include <bits/stdc++.h>
using namespace std;

// it didn't gave tle
vector<int> maxSubsequence(vector<int> &nums, int k)
{
    unordered_map<int, int> um;
    vector<int> a = nums;
    sort(a.begin(), a.end());

    // sliding window of size k
    vector<int> ans;
    int count = k;
    int i = a.size() - 1;
    while (count--)
    {
        um[a[i]]++;
        i--;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (um[nums[i]] > 0)
        {
            ans.push_back(nums[i]);
            um[a[i]]--;
        }
    }

    // sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> nums = {-1, -2, 3, 4};
    int k = 3;
    vector<int> ans = maxSubsequence(nums, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}