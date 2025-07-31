#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    set<vector<int>> us;  // Use set instead of unordered_set for vector<int>
    int n = nums.size();
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    if (us.find(temp) == us.end())
                    {
                        us.insert(temp);
                        ans.push_back(temp);
                    }
                }
            }
        }
    }

    return ans;
}
int main()
{
}