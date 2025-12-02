#include <bits/stdc++.h>
using namespace std;

// this implementaion gave tle
int countTrapezoids(vector<vector<int>> &points)
{
    const int MOD = 1e9 + 7;
    int n = points.size();
    if (n < 4)
        return 0;

    // Group points by y-coordinate
    map<int, vector<int>> groups;
    for (auto &p : points)
    {
        groups[p[1]].push_back(p[0]);
    }

    // Sort x-coordinates in each group
    for (auto &[y, xs] : groups)
    {
        sort(xs.begin(), xs.end());
    }

    long long count = 0;
    auto yvals = vector<int>();
    for (auto &[y, xs] : groups)
    {
        yvals.push_back(y);
    }

    // For each pair of horizontal lines
    for (int i = 0; i < yvals.size(); i++)
    {
        for (int j = i + 1; j < yvals.size(); j++)
        {
            vector<int> &line1 = groups[yvals[i]];
            vector<int> &line2 = groups[yvals[j]];

            // Count pairs from line1 and line2
            // A trapezoid needs 2 points from each line where x1 < x2 on one line
            for (int p1 = 0; p1 < line1.size(); p1++)
            {
                for (int p2 = p1 + 1; p2 < line1.size(); p2++)
                {
                    for (int p3 = 0; p3 < line2.size(); p3++)
                    {
                        for (int p4 = p3 + 1; p4 < line2.size(); p4++)
                        {
                            if (line1[p1] < line1[p2] && line2[p3] < line2[p4])
                            {
                                count = (count + 1) % MOD;
                            }
                        }
                    }
                }
            }
        }
    }

    return count;
}

// its correct implementation
class Solution
{
public:
    static int countTrapezoids(vector<vector<int>> &points)
    {
        const long long mod = 1e9 + 7, n = points.size();
        unordered_map<int, int> freq;
        freq.reserve(n);
        for (auto &p : points)
            freq[p[1]]++;
        long long sum = 0, c2 = 0;
        for (auto &[y, f] : freq)
        {
            if (f <= 1)
                continue;
            const long long c = f * (f - 1LL) / 2LL;
            sum += c;
            c2 += c * c;
        }
        long long ans = sum * sum - c2;
        ans /= 2;
        ans %= mod;
        return ans;
    }
};

int main()
{
}