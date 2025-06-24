#include <bits/stdc++.h>
using namespace std;

// TC: O(n) , from editorial
vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
{
    vector<int> res;
    int r = 0; // unjudged minimum index
    int n = nums.size();
    for (int j = 0; j < n; ++j)
    {
        if (nums[j] == key)
        {
            int l = max(r, j - k);
            r = min(n - 1, j + k) + 1;
            for (int i = l; i < r; ++i)
            {
                res.push_back(i);
            }
        }
    }
    return res;
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