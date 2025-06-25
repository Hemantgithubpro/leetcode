#include <bits/stdc++.h>
using namespace std;

long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
{
    int firstpositiveoccurence1;
    int firstpositiveoccurence2;
    for (int i = 0; i < nums1.size(); i++)
    {
        if (nums1[i] >= 0)
        {
            firstpositiveoccurence1 = i;
            break;
        }
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        if (nums2[i] >= 0)
        {
            firstpositiveoccurence2 = i;
            break;
        }
    }

    long long mini = nums1[0] * nums2[0];

    mini = min(mini, (long long)nums1[0] * nums2[firstpositiveoccurence2]);
    mini = min(mini, (long long)nums2[0] * nums1[firstpositiveoccurence1]);

    mini = min(mini, (long long)nums1[0] * nums2[nums2.size() - 1]);
    mini = min(mini, (long long)nums2[0] * nums1[nums1.size() - 1]);

    return mini;
}

int main()
{
    vector<int> nums1 = {-4, -2, 0, 3};
    vector<int> nums2 = {2, 4};
    int k = 6;
    cout << kthSmallestProduct(nums1, nums2, k);
}