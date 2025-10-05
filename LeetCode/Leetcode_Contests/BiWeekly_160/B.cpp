#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution
{
public:
    int minCostToReach(int m, int n, vector<vector<int>> &waitCost)
    {
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX)));

        // Start at (0,0) at second 1 (odd) with entry cost 1
        dp[0][0][1] = 1; // (0+1) * (0+1) = 1

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If we're at (i,j) on an odd second, we must move
                if (dp[i][j][1] != LLONG_MAX)
                {
                    // Move right
                    if (j + 1 < n)
                    {
                        int entryCost = (i + 1) * (j + 2);
                        dp[i][j + 1][0] = min(dp[i][j + 1][0], dp[i][j][1] + entryCost);
                    }
                    // Move down
                    if (i + 1 < m)
                    {
                        int entryCost = (i + 2) * (j + 1);
                        dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][1] + entryCost);
                    }
                }

                // If we're at (i,j) on an even second, we must wait
                if (dp[i][j][0] != LLONG_MAX)
                {
                    dp[i][j][1] = min(dp[i][j][1], dp[i][j][0] + waitCost[i][j]);
                }
            }
        }

        // Return minimum cost to reach destination on either odd or even second
        long long result = min(dp[m - 1][n - 1][0], dp[m - 1][n - 1][1]);
        return (int)result;
    }
};

// Test function
#include <iostream>
int main()
{
    Solution sol;

    // Test case 1
    vector<vector<int>> waitCost1 = {{1, 2}};
    cout << "Test 1: " << sol.minCostToReach(1, 2, waitCost1) << endl; // Expected: 3

    // Test case 2
    vector<vector<int>> waitCost2 = {{3, 5}, {2, 4}};
    cout << "Test 2: " << sol.minCostToReach(2, 2, waitCost2) << endl; // Expected: 9

    // Test case 3
    vector<vector<int>> waitCost3 = {{6, 1, 4}, {3, 2, 5}};
    cout << "Test 3: " << sol.minCostToReach(2, 3, waitCost3) << endl; // Expected: 16

    return 0;
}