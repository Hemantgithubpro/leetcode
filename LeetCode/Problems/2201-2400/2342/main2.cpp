#include <bits/stdc++.h>
using namespace std;
// it gave tle, bcoz tc: n^2
int sumofdigits(int num)
{
    int ans = 0;
    while (num)
    {
        ans += num % 10;
        num = num / 10;
    }
    return ans;
}
int maximumSum(vector<int> &nums)
{
    int maxi = -1;
    // sort(nums.begin(), nums.end());
    unordered_map<int, int> um;
    for (int num : nums)
    {
        int s = sumofdigits(num);
        if (um.find(s) != um.end())
        {
            // found
            maxi = max(maxi, um[s] + num);
            um[s] = max(um[s], num);
        }
        else
        {
            um[s] = num;
        }
    }
    return maxi;
}

int main()
{
}