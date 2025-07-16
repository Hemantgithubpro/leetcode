// brute force
#include <bits/stdc++.h>
using namespace std;

long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
{
    long long mini = INT_MAX;
    // long long n = min(nums1.size(), nums2.size());
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            mini = min(mini, (long long)nums1[i] * nums2[j]);
        }
    }
    return mini;
}

int main()
{
    vector<int> nums1 = {-4, -2, 0, 3};
    vector<int> nums2 = {2, 4};
    int k = 6;
    cout << kthSmallestProduct(nums1, nums2, k);
}
