#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int countCoveredBuildings(int n, vector<vector<int>> &buildings)
    {
        sort(buildings.begin(), buildings.end());
        unordered_map<int, vector<int>> um; // on this y-axis, at which posn is points in.
        // like {1: {2}
        //   2: {1,2,3}
        //   3: {2}
        //       }
        for (int i = 0; i < n; i++)
        {
            um[buildings[i][1]].push_back(buildings[i][0]);
        }
        vector<int> ys;
        for (auto &p : um)
            ys.push_back(p.first);
        sort(ys.rbegin(), ys.rend());
        set<int> xs;
        int count = 0;
        for (int y : ys)
        {
            for (int x : um[y])
            {
                auto it = xs.upper_bound(x);
                if (it != xs.begin())
                {
                    --it;
                    count++;
                }
            }
            for (int x : um[y])
                xs.insert(x);
        }
        return count;
    }
};