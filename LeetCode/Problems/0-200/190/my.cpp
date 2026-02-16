#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverseBits(int n)
    {
        int32_t res = 0;
        for (int i = 0; i < 32; i++)
        {
            res <<= 1;
            res |= (n & 1);
            n >>= 1;
        }
        return res;
    }
};

int main()
{
    Solution s;
    int n = 43261596;
    cout << s.reverseBits(n);
    return 0;
}