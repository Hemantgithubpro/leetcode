#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            int prev_x = points[i - 1][0];
            int prev_y = points[i - 1][1];
            int curr_x = points[i][0];
            int curr_y = points[i][1];

            int x = abs(curr_x - prev_x);
            int y = abs(curr_y - prev_y);
            int temp = min(x, y);
            int diag = temp;
            x -= temp;
            y -= temp;
            ans += diag;
            ans += max(x, y);
        }

        return ans;
    }
};