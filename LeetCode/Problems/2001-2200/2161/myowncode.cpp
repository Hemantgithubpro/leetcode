#include <bits/stdc++.h>
using namespace std;
// did it in first try, but beats 37.94% or 9ms in TC. could've been improved.


vector<int> pivotArray(vector<int> &nums, int pivot)
{
    // make two queue, which will store num<pivot and num>pivot
    // then create a new vector to push_back in order
    queue<int> less;
    queue<int> more;
    queue<int> equal;

    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < pivot)
            less.push(nums[i]);
        else if (nums[i] == pivot)
            equal.push(nums[i]);
        else
            more.push(nums[i]);
    }
    vector<int> ans;
    while (!less.empty())
    {
        ans.push_back(less.front());
        less.pop();
    }
    while (!equal.empty())
    {
        ans.push_back(equal.front());
        equal.pop();
    }
    while (!more.empty())
    {
        ans.push_back(more.front());
        more.pop();
    }

    return ans;
}

int main()
{
    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;

    vector<int> ans = pivotArray(nums, pivot);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}