#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums)
{
    vector<int> st;
    st.reserve(nums.size());
    int ans = 0;
    for (int x : nums)
    {
        if (x == 0)
        {
            // zeroes act as barriers: reset any ongoing segments
            st.clear();
        }
        else
        {
            // pop any larger values—those segments end before x
            while (!st.empty() && st.back() > x)
            {
                st.pop_back();
            }
            // if stack is empty or top < x, we’ve begun a new segment at value x
            if (st.empty() || st.back() < x)
            {
                st.push_back(x);
                ++ans;
            }
        }
    }
    return ans;
}
