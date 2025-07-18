#include <bits/stdc++.h>
using namespace std;

// Brute force: n^2.
// with division: O(n) product of all, then divide for each i.
// prefix sum: storing left and right products, then multiplying each i to result array.
// optimised prefix sum: instead of storing left and right, operate on result array only.
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();

    vector<int> result(n);
    result[0] = 1;

    for (int i = 1; i < n; i++)
    {
        result[i] = result[i - 1] * nums[i - 1];
    }

    int right_product = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        result[i] *= right_product;
        right_product *= nums[i];
    }
    return result;
}

int main()
{
}