#include <bits/stdc++.h>
using namespace std;

// this is a wrong logic
class Solution
{
public:
    int longestSubsequence(vector<int> &nums)
    {
        // you just need the longest subsequence with the any no. of even and odd no. of odds
        int cntofodd = 0;
        int ans = 0;
        for (int num : nums)
        {
            if (num & 1)
                cntofodd++;
        }
        int n = nums.size();
        int cntofeven = n - cntofodd;
        if (cntofodd & 1)
            return n;
        else
            return n - 1;
    }
};

int main()
{
}