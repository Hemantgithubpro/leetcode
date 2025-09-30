#include <bits/stdc++.h>
using namespace std;

// did it in first try
int triangularSum(vector<int> &nums)
{
    int n = nums.size();
    for (int i = n - 1; i > 0; i--)
    {
        vector<int> n2(i);
        for (int j = 0; j < i; j++)
        {
            n2[j] = nums[j] + nums[j + 1];
            n2[j] %= 10;
        }
        nums = n2;
    }
    return nums[0];
}

int main()
{
}