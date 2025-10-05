#include <bits/stdc++.h>
using namespace std;

// subarray in array of size n: n(n+1)/2
// subset in array of size n: 2^n, Each element has two choices: in or out

int subsetXORSum(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int x = nums[i];
        sum += x;
        for (int j = i + 1; j < nums.size(); j++)
        {
            x = x ^ nums[j];
            sum += x;
        }
    }
    return sum;
}

int main()
{
}