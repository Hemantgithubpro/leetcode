#include <bits/stdc++.h>
using namespace std;

// it'll give tle
vector<int> maxSubsequence(vector<int> &nums, int k)
{
    vector<int> a = nums;
    sort(a.begin(), a.end());

    long long maxi = INT_MIN;
    // sliding window of size k
    vector<int> ans;
    int count = k;
    int i = a.size() - 1;
    while (count--)
    {
        ans.push_back(a[i]);
        i--;
    }
    sort(ans.begin(),ans.end());
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