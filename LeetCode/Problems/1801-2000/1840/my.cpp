#include <bits/stdc++.h>
using namespace std;

// did not understand much, but knew, about my forward and reverse pass approach
// but did not get the sorting approach
// soln : https://leetcode.com/problems/maximum-building-height/solutions/8346225/maximum-building-height-greedy-linear-al-4sar/?envType=daily-question&envId=2026-06-20
class Solution
{
public:
    int maxBuilding(int n, vector<vector<int>> &restrictions)
    {
        // h -> 0 to n-1
        // h[0] = 0
        // for i: 1 to n-1 { abs(h[i]-h[i-1]) <= 1 }

        unordered_map<int, int> um;
        for (int i = 0; i < restrictions.size(); i++)
        {
            int first = restrictions[i][0];
            int sec = restrictions[i][1];
            um[first] = sec;
        }
        // easier to find in map

        vector<int> h(n, 0);

        return *max_element(h.begin(), h.end());
    }
};

int main()
{
}