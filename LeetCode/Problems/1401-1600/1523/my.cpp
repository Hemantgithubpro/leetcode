#include <bits/stdc++.h>
using namespace std;

int main()
{
}
class Solution
{
public:
    int countOdds(int low, int high)
    {
        int ans = (high - low) / 2;
        // odd-odd, even-odd, odd-even, even-even
        // 3-7, 4-9, 1-4, 4-8
        // a+1, a+1, a+1, a
        if (low & 1 || high & 1)
            ans++;
        return ans;
    }
};