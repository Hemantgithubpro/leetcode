#include <bits/stdc++.h>
using namespace std;

vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
{
    vector<int> ans;
    unordered_set<int> us;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (abs(i - j) <= k && nums[j] == key)
            {
                // ans.push_back(i);
                us.insert(i);
            }
        }
    }

    for (auto it = us.begin(); it != us.end(); it++)
    {
        ans.push_back(*it);
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> nums = {3, 4, 9, 1, 3, 9, 5};
    int key = 9;
    int k = 1;
    // vector<int> nums = {2, 2, 2, 2, 2};
    // int key = 2;
    // int k = 2;
    for (auto it : findKDistantIndices(nums, key, k))
    {
        cout << it << " ";
    }

    // cout << findKDistantIndices(nums, key, k);
}