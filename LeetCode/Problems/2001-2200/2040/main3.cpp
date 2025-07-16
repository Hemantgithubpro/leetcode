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

    long long mini = INT_MAX;

    if (nums1[0] >= 0 && nums2[0] >= 0)
    {
        
    }
    else if (nums1[0] < 0 && nums2[0] >= 0)
    {
    }
    else if (nums1[0] >= 0 && nums2[0] < 0)
    {
    }
    else    // nums1[0]<0 && nums2[0]<0
    {
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