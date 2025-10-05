#include <bits/stdc++.h>
using namespace std;

int partition_algo(vector<int> &nums, int L, int R)
{
    int P = nums[L];
    int i = L+1;
    int j = R;

    while (i <= j)
    {
        if (nums[i] < P && nums[j] > P)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        if (nums[i] >= P)
            i++;
        if (nums[j] <= P)
            j--;
    }
    swap(nums[L], nums[j]);
    return j;
}

int findKthLargest(vector<int> &nums, int k)
{
    // Quick Select algorithm, avg case O(n), worst case O(n^2)
    int n = nums.size();
    int L = 0, R = n - 1;
    int pivot = 0;

    // kth largest pivot element nums[k-1]

    while (true)
    {
        pivot = partition_algo(nums, L, R);
        if (pivot == k - 1)
            break;
        else if (pivot > k - 1)
            R = pivot - 1;
        else
            L = pivot + 1;
    }
    return nums[pivot];
}