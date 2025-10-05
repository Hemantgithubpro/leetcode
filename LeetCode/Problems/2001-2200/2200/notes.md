- did it in first attempt, but i'm seeing the solution to learn the most optimal way.
- my own code is not optimal, but it works. TC: O(n^2), SC: O(n)

## Optimal Solution

```cpp
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        int r = 0;  // unjudged minimum index
        int n = nums.size();
        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                int l = max(r, j - k);
                r = min(n - 1, j + k) + 1;
                for (int i = l; i < r; ++i) {
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};
```