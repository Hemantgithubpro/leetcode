#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;     // Pointer for the last element in nums1's valid part
    int j = n - 1;     // Pointer for the last element in nums2
    int k = m + n - 1; // Pointer for the last position in nums1

    // Merge nums2 into nums1 starting from the end
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // If there are remaining elements in nums2, copy them
    while (j >= 0)
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main()
{
    vector<int> nums1 = {4, 0, 0, 0, 0, 0};
    // vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 1;
    vector<int> nums2 = {1, 2, 3, 5, 6};
    // vector<int> nums2 = {2,5,6};
    int n = 5;

    cout << "Before merge: ";
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;

    merge(nums1, m, nums2, n);

    cout << "After merge: ";
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;

    return 0;
}