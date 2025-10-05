# I did not understand this problem at all, so I'm looking at solution video by Neetcode

# Now I understand it, and I will try to implement it myself

## Brute Force
- For each cell, do a DFS to see if we can reach both oceans
- Time Complexity: O(m * n * (m + n)) where m and n are the dimensions of the grid
- Space Complexity: O(m * n) for the visited set in DFS

## Optimized Approach
- Start DFS from all cells adjacent to the Pacific Ocean and mark all reachable cells
- Start DFS from all cells adjacent to the Atlantic Ocean and mark all reachable cells
- The intersection of the two sets of reachable cells gives the result
- Time Complexity: O(m * n) since each cell is processed at most twice
- Space Complexity: O(m * n) for the visited sets