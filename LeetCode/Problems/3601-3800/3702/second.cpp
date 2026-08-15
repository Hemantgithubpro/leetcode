#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool allzero(vector<int> &nums)
    {
        for (int n : nums)
            if (n != 0)
                return false;
        return true;
    }
    int longestSubsequence(vector<int> &nums)
    {
        // check if the whole array's xor is zero or not. if its zero, return
        // n-1, and if non-zero, return n
        int n = nums.size();
        int a = 0;
        if (allzero(nums))
            return 0;
        for (int num : nums)
            a ^= num;
        if (a == 0)
            return n - 1;
        else
            return n;
    }
};

int main()
{
}